#pragma once

#include <cstdint>
#include <functional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace marx::fix {

/// A single parsed FIX tag=value pair.
struct FixField {
    int         tag;
    std::string value;
};

/// A parsed FIX message: header fields + body fields + trailer.
/// This is a flat representation — no distinction between header/body/trailer
/// at this level (the caller separates them by tag number).
struct FixMessage {
    std::string                            msgType;    ///< Tag 35 value
    std::uint32_t                          msgSeqNum = 0; ///< Tag 34 value
    std::string                            senderCompId; ///< Tag 49
    std::string                            targetCompId; ///< Tag 56
    std::vector<FixField>                  fields;     ///< All tag=value pairs
    std::unordered_map<int, std::string>   fieldMap;   ///< Tag → value lookup

    /// Convenience: get a field value by tag, or empty string if missing.
    const std::string& get(int tag) const {
        static const std::string empty;
        auto it = fieldMap.find(tag);
        return (it != fieldMap.end()) ? it->second : empty;
    }

    /// Check if a tag is present.
    bool has(int tag) const {
        return fieldMap.find(tag) != fieldMap.end();
    }
};

/// Decodes raw FIX byte streams into FixMessage structs.
///
/// Handles:
///   - SOH-delimited (0x01) tag=value parsing
///   - Streaming: accumulates partial data across onData() calls
///   - BeginString (tag 8) / BodyLength (tag 9) / CheckSum (tag 10) validation
///   - Extracts MsgType (tag 35) for dispatch
///
/// Usage:
///   decoder.onMessage = [](FixMessage msg) { ... };
///   decoder.onData(buf, len);  // call repeatedly with incoming bytes
class FixDecoder {
public:
    FixDecoder() = default;

    /// Callback invoked for each fully decoded message.
    std::function<void(FixMessage)> onMessage;

    /// Callback invoked on decode error (malformed message, bad checksum).
    std::function<void(const std::string& error)> onError;

    /// Feed raw bytes from the wire.  May produce 0, 1, or multiple
    /// onMessage callbacks (if multiple FIX messages arrived in one read).
    void onData(const char* data, std::size_t len);

    /// Reset internal buffer (e.g. on reconnect).
    void reset();

private:
    /// Try to extract a complete FIX message from the accumulation buffer.
    /// Returns true if a message was extracted (and onMessage called).
    bool tryExtractMessage();

    /// Parse a single complete FIX message string into a FixMessage struct.
    bool parseMessage(std::string_view raw, FixMessage& out);

    /// Compute FIX checksum over a range of bytes.
    static int computeChecksum(std::string_view data);

    std::string buffer_;  ///< Accumulation buffer for partial reads
};

} // namespace marx::fix
