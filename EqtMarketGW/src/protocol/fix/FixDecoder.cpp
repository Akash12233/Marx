#include "protocol/fix/FixDecoder.h"

#include <charconv>
#include <iostream>
#include <sstream>

namespace marx::fix {

static constexpr char SOH = '\x01';  // FIX field delimiter

// ---------------------------------------------------------------------------
// onData — accumulate bytes and try to extract complete messages
// ---------------------------------------------------------------------------
void FixDecoder::onData(const char* data, std::size_t len)
{
    buffer_.append(data, len);

    // A single read may contain multiple FIX messages
    while (tryExtractMessage()) {
        // keep extracting
    }
}

// ---------------------------------------------------------------------------
// reset
// ---------------------------------------------------------------------------
void FixDecoder::reset()
{
    buffer_.clear();
}

// ---------------------------------------------------------------------------
// tryExtractMessage
// ---------------------------------------------------------------------------
bool FixDecoder::tryExtractMessage()
{
    // Minimum FIX message: "8=FIX.4.2|9=5|35=0|10=xxx|"
    // We need at least the BeginString, BodyLength, and CheckSum fields.

    // Step 1: Find "8=" at the start
    auto pos8 = buffer_.find("8=");
    if (pos8 == std::string::npos) {
        return false;
    }

    // Discard any garbage before "8="
    if (pos8 > 0) {
        buffer_.erase(0, pos8);
    }

    // Step 2: Find end of BeginString field (first SOH after "8=")
    auto endBeginStr = buffer_.find(SOH, 2);
    if (endBeginStr == std::string::npos) {
        return false;  // need more data
    }

    // Step 3: Find "9=" (BodyLength) — should be right after BeginString SOH
    auto pos9 = buffer_.find("9=", endBeginStr + 1);
    if (pos9 == std::string::npos) {
        return false;
    }

    auto endBodyLen = buffer_.find(SOH, pos9 + 2);
    if (endBodyLen == std::string::npos) {
        return false;
    }

    // Parse BodyLength value
    std::string_view bodyLenStr(buffer_.data() + pos9 + 2, endBodyLen - pos9 - 2);
    int bodyLength = 0;
    auto [ptr, ec] = std::from_chars(bodyLenStr.data(),
                                      bodyLenStr.data() + bodyLenStr.size(),
                                      bodyLength);
    if (ec != std::errc{} || bodyLength <= 0) {
        // Invalid body length — skip this message
        if (onError) onError("Invalid BodyLength: " + std::string(bodyLenStr));
        buffer_.erase(0, endBodyLen + 1);
        return true;  // try again with remaining data
    }

    // Step 4: Check if we have enough bytes for body + checksum
    // Body starts after the BodyLength SOH
    std::size_t bodyStart = endBodyLen + 1;
    // After body, we expect "10=xxx|" (7 bytes: "10=", 3 digits, SOH)
    std::size_t messageEnd = bodyStart + bodyLength + 7;

    if (buffer_.size() < messageEnd) {
        return false;  // need more data
    }

    // Step 5: Find the checksum field "10="
    auto pos10 = buffer_.find("10=", bodyStart + bodyLength);
    if (pos10 == std::string::npos || pos10 != bodyStart + bodyLength) {
        // Checksum not where expected — try to find it
        pos10 = buffer_.find("10=", bodyStart + bodyLength);
        if (pos10 == std::string::npos) {
            return false;
        }
    }

    auto endChecksum = buffer_.find(SOH, pos10);
    if (endChecksum == std::string::npos) {
        return false;
    }

    // Step 6: Extract the full message
    std::string_view fullMsg(buffer_.data(), endChecksum + 1);

    // Step 7: Validate checksum
    // Checksum is computed over everything from "8=" to (but not including) "10="
    std::string_view checksumBody(buffer_.data(), pos10);
    int computedChecksum = computeChecksum(checksumBody);

    std::string_view checksumStr(buffer_.data() + pos10 + 3, endChecksum - pos10 - 3);
    int declaredChecksum = 0;
    std::from_chars(checksumStr.data(),
                    checksumStr.data() + checksumStr.size(),
                    declaredChecksum);

    if (computedChecksum != declaredChecksum) {
        if (onError) {
            std::ostringstream oss;
            oss << "Checksum mismatch: computed=" << computedChecksum
                << " declared=" << declaredChecksum;
            onError(oss.str());
        }
        // Skip this message
        buffer_.erase(0, endChecksum + 1);
        return true;
    }

    // Step 8: Parse fields
    FixMessage msg;
    if (parseMessage(fullMsg, msg)) {
        if (onMessage) {
            onMessage(std::move(msg));
        }
    }

    // Remove processed message from buffer
    buffer_.erase(0, endChecksum + 1);
    return true;
}

// ---------------------------------------------------------------------------
// parseMessage — split a complete FIX string into tag=value pairs
// ---------------------------------------------------------------------------
bool FixDecoder::parseMessage(std::string_view raw, FixMessage& out)
{
    std::size_t pos = 0;

    while (pos < raw.size()) {
        // Find '='
        auto eqPos = raw.find('=', pos);
        if (eqPos == std::string_view::npos) break;

        // Find SOH
        auto sohPos = raw.find(SOH, eqPos + 1);
        if (sohPos == std::string_view::npos) break;

        // Parse tag
        int tag = 0;
        auto tagStr = raw.substr(pos, eqPos - pos);
        auto [p, e] = std::from_chars(tagStr.data(),
                                       tagStr.data() + tagStr.size(),
                                       tag);
        if (e != std::errc{}) {
            pos = sohPos + 1;
            continue;
        }

        std::string value(raw.substr(eqPos + 1, sohPos - eqPos - 1));

        // Store in both vector and map
        out.fields.push_back({tag, value});
        out.fieldMap[tag] = value;

        // Extract well-known header fields
        switch (tag) {
            case 35: out.msgType = value; break;
            case 34: {
                std::from_chars(value.data(), value.data() + value.size(),
                                out.msgSeqNum);
                break;
            }
            case 49: out.senderCompId = value; break;
            case 56: out.targetCompId = value; break;
            default: break;
        }

        pos = sohPos + 1;
    }

    return !out.msgType.empty();
}

// ---------------------------------------------------------------------------
// computeChecksum
// ---------------------------------------------------------------------------
int FixDecoder::computeChecksum(std::string_view data)
{
    int sum = 0;
    for (char c : data) {
        sum += static_cast<unsigned char>(c);
    }
    return sum % 256;
}

} // namespace marx::fix
