#ifndef JXMPP_JINGLESESSIONIMPL_H
#define JXMPP_JINGLESESSIONIMPL_H

#include <map>
#include <memory>

#include <JXMPP/Jingle/JingleSession.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class IQRouter;

    class JingleSessionImpl : public JingleSession {
            friend class JingleResponder;
        public:
            typedef std::shared_ptr<JingleSessionImpl> ref;

            JingleSessionImpl(const JID& initiator, const JID&, const std::string& id, IQRouter* router);

            virtual void sendInitiate(const JingleContentID&, JingleDescription::ref, JingleTransportPayload::ref);
            virtual void sendTerminate(JinglePayload::Reason::Type reason);
            virtual void sendInfo(std::shared_ptr<Payload>);
            virtual void sendAccept(const JingleContentID&, JingleDescription::ref, JingleTransportPayload::ref);
            virtual std::string sendTransportInfo(const JingleContentID&, JingleTransportPayload::ref);
            virtual void sendTransportAccept(const JingleContentID&, JingleTransportPayload::ref);
            virtual void sendTransportReject(const JingleContentID&, JingleTransportPayload::ref);
            virtual void sendTransportReplace(const JingleContentID&, JingleTransportPayload::ref);

        private:
            typedef std::shared_ptr<GenericRequest<JinglePayload> > RequestRef;

            void handleIncomingAction(JinglePayload::ref);

            std::string sendSetRequest(JinglePayload::ref payload);
            JinglePayload::ref createPayload() const;
            void handleRequestResponse(RequestRef);

        private:
            IQRouter *iqRouter;
            JID peerJID;
            typedef std::map<RequestRef, boost::signals2::connection > RequestsMap;
            RequestsMap pendingRequests;
    };
}

#endif // JXMPP_JINGLESESSIONIMPL_H
