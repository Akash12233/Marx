#pragma once

#include "protocol/fix/FixDecoder.h"

#include <cstdint>
#include <string>
#include <vector>

namespace marx::fix {

/// Encodes FIX messages into wire-format byte buffers.
///
/// Handles:
///   - SOH-delimited tag=value serialization
///   - BeginString (tag 8) / BodyLength (tag 9) / CheckSum (tag 10) computation
///   - Standard header fields (SenderCompID, TargetCompID, MsgSeqNum, SendingTime)
///
/// Usage:
///   FixEncoder encoder("FIX.4.2");
///   auto bytes = encoder.encode("A", seqNum, sender, target, bodyFields);
class FixEncoder {
public:
    /// @param beginString  FIX version string, e.g. "FIX.4.2" or "FIX.4.4"
    explicit FixEncoder(std::string beginString = "FIX.4.2");

    /// Encode a complete FIX message to wire bytes.
    ///
    /// @param msgType       FIX MsgType value (e.g. "A" for Logon, "D" for NewOrderSingle)
    /// @param msgSeqNum     Outgoing sequence number
    /// @param senderCompId  SenderCompID (tag 49)
    /// @param targetCompId  TargetCompID (tag 56)
    /// @param bodyFields    The message body fields (everything between header and trailer)
    /// @return Wire-format bytes ready to send
    std::vector<char> encode(const std::string& msgType,
                             std::uint32_t msgSeqNum,
                             const std::string& senderCompId,
                             const std::string& targetCompId,
                             const std::vector<FixField>& bodyFields);

    /// Convenience: encode from a FixMessage struct (re-serializes with
    /// correct BodyLength and CheckSum).
    std::vector<char> encode(const FixMessage& msg,
                             std::uint32_t msgSeqNum,
                             const std::string& senderCompId,
                             const std::string& targetCompId);

private:
    /// Get current UTC timestamp in FIX format: YYYYMMDD-HH:MM:SS.sss
    static std::string currentTimestamp();

    /// Compute FIX checksum.
    static int computeChecksum(const std::string& data);

    /// Format checksum as 3-digit zero-padded string.
    static std::string formatChecksum(int checksum);

    std::string beginString_;
};

} // namespace marx::fix
