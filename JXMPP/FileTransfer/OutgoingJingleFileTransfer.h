#ifndef JXMPP_OUTGOINGJINGLEFILETRANSFER_H
#define JXMPP_OUTGOINGJINGLEFILETRANSFER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <boost/optional/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleFileTransferFileInfo.h>
#include <JXMPP/FileTransfer/FileTransferOptions.h>
#include <JXMPP/FileTransfer/JingleFileTransfer.h>
#include <JXMPP/FileTransfer/OutgoingFileTransfer.h>
#include <JXMPP/Jingle/JingleContentID.h>
#include <JXMPP/Network/Timer.h>

namespace JXMPP {
    class CryptoProvider;
    class FileTransferTransporterFactory;
    class IDGenerator;
    class IncrementalBytestreamHashCalculator;
    class ReadBytestream;
    class TimerFactory;
    class TransportSession;

    class JXMPP_API OutgoingJingleFileTransfer : public OutgoingFileTransfer, public JingleFileTransfer {
        public:
            OutgoingJingleFileTransfer(
                const JID& to,
                std::shared_ptr<JingleSession>,
                std::shared_ptr<ReadBytestream>,
                FileTransferTransporterFactory*,
                TimerFactory*,
                IDGenerator*,
                const JingleFileTransferFileInfo&,
                const FileTransferOptions&,
                CryptoProvider*);
            virtual ~OutgoingJingleFileTransfer() override;

            virtual void start() override;
            virtual void cancel() override;

        private:
            enum State {
                Initial,
                GeneratingInitialLocalCandidates,
                WaitingForAccept,
                TryingCandidates,
                WaitingForPeerProxyActivate,
                WaitingForLocalProxyActivate,
                WaitingForCandidateAcknowledge,
                FallbackRequested,
                Transferring,
                WaitForTermination,
                Finished
            };

            virtual void handleSessionAcceptReceived(const JingleContentID&, std::shared_ptr<JingleDescription>, std::shared_ptr<JingleTransportPayload>) override;
            virtual void handleSessionTerminateReceived(boost::optional<JinglePayload::Reason> reason) override;
            virtual void handleTransportAcceptReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>) override;
            virtual void handleTransportRejectReceived(const JingleContentID &, std::shared_ptr<JingleTransportPayload>) override;
            virtual void startTransferViaRemoteCandidate() override;
            virtual void startTransferViaLocalCandidate() override;
            void startTransferringIfCandidateAcknowledged();

            virtual void handleLocalTransportCandidatesGenerated(const std::string& s5bSessionID, const std::vector<JingleS5BTransportPayload::Candidate>&, const std::string& dstAddr) override;
            virtual void handleTransportInfoAcknowledged(const std::string& id) override;

            virtual JingleContentID getContentID() const override;

            virtual void terminate(JinglePayload::Reason::Type reason) override;

            virtual void fallback() override;
            void handleTransferFinished(boost::optional<FileTransferError>);

            void sendSessionInfoHash();

            virtual void startTransferring(std::shared_ptr<TransportSession>) override;

            virtual bool hasPriorityOnCandidateTie() const override;
            virtual bool isWaitingForPeerProxyActivate() const override;
            virtual bool isWaitingForLocalProxyActivate() const override;
            virtual bool isTryingCandidates() const override;
            virtual std::shared_ptr<TransportSession> createLocalCandidateSession() override;
            virtual std::shared_ptr<TransportSession> createRemoteCandidateSession() override;

            void handleWaitForRemoteTerminationTimeout();

            void stopAll();
            void setInternalState(State state);
            void setFinishedState(FileTransfer::State::Type, const boost::optional<FileTransferError>& error);

            static FileTransfer::State::Type getExternalState(State state);

        private:
            IDGenerator* idGenerator;
            std::shared_ptr<ReadBytestream> stream;
            JingleFileTransferFileInfo fileInfo;
            FileTransferOptions options;
            JingleContentID contentID;
            IncrementalBytestreamHashCalculator* hashCalculator;
            State state;
            bool candidateAcknowledged;

            Timer::ref waitForRemoteTermination;

            boost::signals2::connection processedBytesConnection;
            boost::signals2::connection transferFinishedConnection;
    };

}

#endif // JXMPP_OUTGOINGJINGLEFILETRANSFER_H
