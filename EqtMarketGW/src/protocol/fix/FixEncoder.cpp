#include "protocol/fix/FixEncoder.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace marx::fix {

static constexpr char SOH = '\x01';

FixEncoder::FixEncoder(std::string beginString)
    : beginString_(std::move(beginString))
{
}

// ---------------------------------------------------------------------------
// encode (from individual parameters)
// ---------------------------------------------------------------------------
std::vector<char> FixEncoder::encode(const std::string& msgType,
                                      std::uint32_t msgSeqNum,
                                      const std::string& senderCompId,
                                      const std::string& targetCompId,
                                      const std::vector<FixField>& bodyFields)
{
    // Build the body: header fields (35, 49, 56, 34, 52) + message body fields
    // Everything between BeginString/BodyLength and CheckSum.
    std::string body;

    // Standard header fields (after 8= and 9=)
    body += "35=" + msgType + SOH;
    body += "49=" + senderCompId + SOH;
    body += "56=" + targetCompId + SOH;
    body += "34=" + std::to_string(msgSeqNum) + SOH;
    body += "52=" + currentTimestamp() + SOH;

    // Message body fields
    for (const auto& field : bodyFields) {
        body += std::to_string(field.tag) + "=" + field.value + SOH;
    }

    // Now build the full message:
    // 8=BeginString|9=BodyLength|<body>10=CheckSum|
    std::string header;
    header += "8=" + beginString_ + SOH;
    header += "9=" + std::to_string(body.size()) + SOH;

    std::string messageWithoutChecksum = header + body;

    int checksum = computeChecksum(messageWithoutChecksum);
    std::string trailer = "10=" + formatChecksum(checksum) + SOH;

    std::string fullMessage = messageWithoutChecksum + trailer;

    return std::vector<char>(fullMessage.begin(), fullMessage.end());
}

// ---------------------------------------------------------------------------
// encode (from FixMessage struct)
// ---------------------------------------------------------------------------
std::vector<char> FixEncoder::encode(const FixMessage& msg,
                                      std::uint32_t msgSeqNum,
                                      const std::string& senderCompId,
                                      const std::string& targetCompId)
{
    // Extract body fields (exclude header/trailer tags: 8, 9, 10, 35, 49, 56, 34, 52)
    std::vector<FixField> bodyFields;
    for (const auto& field : msg.fields) {
        switch (field.tag) {
            case 8: case 9: case 10: case 35: case 49: case 56: case 34: case 52:
                continue;  // skip header/trailer fields
            default:
                bodyFields.push_back(field);
                break;
        }
    }

    return encode(msg.msgType, msgSeqNum, senderCompId, targetCompId, bodyFields);
}

// ---------------------------------------------------------------------------
// currentTimestamp — YYYYMMDD-HH:MM:SS.sss
// ---------------------------------------------------------------------------
std::string FixEncoder::currentTimestamp()
{
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                  now.time_since_epoch()) % 1000;

    std::tm utc{};
    gmtime_r(&time, &utc);

    std::ostringstream oss;
    oss << std::put_time(&utc, "%Y%m%d-%H:%M:%S");
    oss << '.' << std::setfill('0') << std::setw(3) << ms.count();
    return oss.str();
}

// ---------------------------------------------------------------------------
// computeChecksum
// ---------------------------------------------------------------------------
int FixEncoder::computeChecksum(const std::string& data)
{
    int sum = 0;
    for (char c : data) {
        sum += static_cast<unsigned char>(c);
    }
    return sum % 256;
}

// ---------------------------------------------------------------------------
// formatChecksum — 3-digit zero-padded
// ---------------------------------------------------------------------------
std::string FixEncoder::formatChecksum(int checksum)
{
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(3) << checksum;
    return oss.str();
}

} // namespace marx::fix
