#ifndef JXMPP_ABSTRACTJINGLESESSIONLISTENER_H
#define JXMPP_ABSTRACTJINGLESESSIONLISTENER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Jingle/JingleSessionListener.h>

namespace JXMPP {
    class JXMPP_API AbstractJingleSessionListener : public JingleSessionListener {
        public:
            virtual void handleSessionAcceptReceived(const JingleContentID&, std::shared_ptr<JingleDescription>, std::shared_ptr<JingleTransportPayload>) override;
            virtual void handleSessionInfoReceived(std::shared_ptr<JinglePayload>) override;
            virtual void handleSessionTerminateReceived(boost::optional<JinglePayload::Reason>) override;
            virtual void handleTransportAcceptReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>) override;
            virtual void handleTransportInfoReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>) override;
            virtual void handleTransportRejectReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>) override;
            virtual void handleTransportReplaceReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>) override;
            virtual void handleTransportInfoAcknowledged(const std::string& id) override;
    };
}

#endif // JXMPP_ABSTRACTJINGLESESSIONLISTENER_H
