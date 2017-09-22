#ifndef JXMPP_FILETRANSFERTRANSPORTER_H
#define JXMPP_FILETRANSFERTRANSPORTER_H

#include <vector>

#include <boost/optional/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleS5BTransportPayload.h>

namespace JXMPP {
    class TransportSession;
    class ErrorPayload;
    class ReadBytestream;
    class WriteBytestream;

    /**
     * @brief The FileTransferTransporter class is an abstract factory definition
     * to generate SOCKS5 bytestream transports or IBB bytestreams for use in file
     * transfers.
     */
    class JXMPP_API FileTransferTransporter {
        public:
            virtual ~FileTransferTransporter();

            virtual void startGeneratingLocalCandidates() = 0;
            virtual void stopGeneratingLocalCandidates() = 0;

            virtual void addRemoteCandidates(
                    const std::vector<JingleS5BTransportPayload::Candidate>&, const std::string&) = 0;
            virtual void startTryingRemoteCandidates() = 0;
            virtual void stopTryingRemoteCandidates() = 0;

            virtual void startActivatingProxy(const JID& proxy) = 0;
            virtual void stopActivatingProxy() = 0;

            virtual std::shared_ptr<TransportSession> createIBBSendSession(
                    const std::string& sessionID, unsigned int blockSize, std::shared_ptr<ReadBytestream>) = 0;
            virtual std::shared_ptr<TransportSession> createIBBReceiveSession(
                    const std::string& sessionID, unsigned long long size, std::shared_ptr<WriteBytestream>) = 0;
            virtual std::shared_ptr<TransportSession> createRemoteCandidateSession(
                    std::shared_ptr<ReadBytestream>, const JingleS5BTransportPayload::Candidate& candidate) = 0;
            virtual std::shared_ptr<TransportSession> createRemoteCandidateSession(
                    std::shared_ptr<WriteBytestream>, const JingleS5BTransportPayload::Candidate& candidate) = 0;
            virtual std::shared_ptr<TransportSession> createLocalCandidateSession(
                    std::shared_ptr<ReadBytestream>, const JingleS5BTransportPayload::Candidate& candidate) = 0;
            virtual std::shared_ptr<TransportSession> createLocalCandidateSession(
                    std::shared_ptr<WriteBytestream>, const JingleS5BTransportPayload::Candidate& candidate) = 0;

            boost::signals2::signal<void (const std::string& /* sessionID */, const std::vector<JingleS5BTransportPayload::Candidate>&, const std::string& /* dstAddr */)> onLocalCandidatesGenerated;
            boost::signals2::signal<void (const std::string& /* sessionID */, const boost::optional<JingleS5BTransportPayload::Candidate>&)> onRemoteCandidateSelectFinished;
            boost::signals2::signal<void (const std::string& /* sessionID */, std::shared_ptr<ErrorPayload>)> onProxyActivated;
    };
}

#endif // JXMPP_FILETRANSFERTRANSPORTER_H
