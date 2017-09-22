#ifndef JXMPP_FAKEJINGLESESSION_H
#define JXMPP_FAKEJINGLESESSION_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>
#include <string>
#include <vector>

#include <boost/signals2.hpp>
#include <boost/variant.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SimpleIDGenerator.h>
#include <JXMPP/Elements/JinglePayload.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Jingle/JingleContentID.h>
#include <JXMPP/Jingle/JingleSession.h>

namespace JXMPP {
    class JingleContentID;

    class JXMPP_API FakeJingleSession : public JingleSession {
        public:
        struct InitiateCall {
            InitiateCall(JingleContentID contentId, JingleDescription::ref desc, JingleTransportPayload::ref payL) : id(contentId), description(desc), payload(payL) {}
            JingleContentID id;
            JingleDescription::ref description;
            JingleTransportPayload::ref payload;
        };

        struct  TerminateCall {
            TerminateCall(JinglePayload::Reason::Type r) : reason(r) {}
            JinglePayload::Reason::Type reason;
        };

        struct InfoCall {
            InfoCall(std::shared_ptr<Payload> info) : payload(info) {}
            std::shared_ptr<Payload> payload;
        };

        struct AcceptCall {
            AcceptCall(JingleContentID contentId, JingleDescription::ref desc, JingleTransportPayload::ref payL) : id(contentId), description(desc), payload(payL) {}
            JingleContentID id;
            JingleDescription::ref description;
            JingleTransportPayload::ref payload;
        };

        struct InfoTransportCall {
            InfoTransportCall(JingleContentID contentId, JingleTransportPayload::ref payL) : id(contentId), payload(payL) {}
            JingleContentID id;
            JingleTransportPayload::ref payload;
        };

        struct AcceptTransportCall {
            AcceptTransportCall(JingleContentID contentId, JingleTransportPayload::ref payL) : id(contentId), payload(payL) {}
            JingleContentID id;
            JingleTransportPayload::ref payload;
        };

        struct RejectTransportCall {
            RejectTransportCall(JingleContentID contentId, JingleTransportPayload::ref payL) : id(contentId), payload(payL) {}
            JingleContentID id;
            JingleTransportPayload::ref payload;
        };

        struct ReplaceTransportCall {
            ReplaceTransportCall(JingleContentID contentId, JingleTransportPayload::ref payL) : id(contentId), payload(payL) {}
            JingleContentID id;
            JingleTransportPayload::ref payload;
        };

        typedef boost::variant<InitiateCall, TerminateCall, AcceptCall, InfoCall, InfoTransportCall, AcceptTransportCall, RejectTransportCall, ReplaceTransportCall> Command;

        public:
            typedef std::shared_ptr<FakeJingleSession> ref;

            FakeJingleSession(const JID& initiator, const std::string& id);
            virtual ~FakeJingleSession() override;

            virtual void sendInitiate(const JingleContentID&, JingleDescription::ref, JingleTransportPayload::ref) override;
            virtual void sendTerminate(JinglePayload::Reason::Type reason) override;
            virtual void sendInfo(std::shared_ptr<Payload>) override;
            virtual void sendAccept(const JingleContentID&, JingleDescription::ref, JingleTransportPayload::ref = JingleTransportPayload::ref()) override;
            virtual std::string sendTransportInfo(const JingleContentID&, JingleTransportPayload::ref) override;
            virtual void sendTransportAccept(const JingleContentID&, JingleTransportPayload::ref) override;
            virtual void sendTransportReject(const JingleContentID&, JingleTransportPayload::ref) override;
            virtual void sendTransportReplace(const JingleContentID&, JingleTransportPayload::ref) override;

            void handleSessionTerminateReceived(boost::optional<JinglePayload::Reason>);
            void handleSessionAcceptReceived(const JingleContentID&, std::shared_ptr<JingleDescription>, std::shared_ptr<JingleTransportPayload>);
            void handleSessionInfoReceived(std::shared_ptr<JinglePayload>);

            void handleTransportReplaceReceived(const JingleContentID&, JingleTransportPayload::ref);
            void handleTransportAcceptReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>);
            void handleTransportInfoReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>);
            void handleTransportRejectReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>);
            void handleTransportInfoAcknowledged(const std::string& id);

        public:
            std::vector<Command> calledCommands;
            SimpleIDGenerator idGenerator;
    };
}

#endif // JXMPP_FAKEJINGLESESSION_H
