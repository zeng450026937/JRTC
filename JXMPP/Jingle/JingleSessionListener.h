#ifndef JXMPP_JINGLESESSIONLISTENER_H
#define JXMPP_JINGLESESSIONLISTENER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JinglePayload.h>

namespace JXMPP {
    class JingleContentID;
    class JingleTransportPayload;
    class JingleDescription;

    class JXMPP_API JingleSessionListener {
        public:
            virtual ~JingleSessionListener();

            virtual void handleSessionAcceptReceived(
                    const JingleContentID&,
                    std::shared_ptr<JingleDescription>,
                    std::shared_ptr<JingleTransportPayload>) = 0;
            virtual void handleSessionInfoReceived(std::shared_ptr<JinglePayload>) = 0;
            virtual void handleSessionTerminateReceived(boost::optional<JinglePayload::Reason>) = 0;
            virtual void handleTransportAcceptReceived(
                    const JingleContentID&,
                    std::shared_ptr<JingleTransportPayload>) = 0;
            virtual void handleTransportInfoReceived(
                    const JingleContentID&,
                    std::shared_ptr<JingleTransportPayload>) = 0;
            virtual void handleTransportRejectReceived(
                    const JingleContentID&, std::shared_ptr<JingleTransportPayload>) = 0;
            virtual void handleTransportReplaceReceived(
                    const JingleContentID&, std::shared_ptr<JingleTransportPayload>) = 0;

            virtual void handleTransportInfoAcknowledged(const std::string& id) = 0;
    };
}

#endif // JXMPP_JINGLESESSIONLISTENER_H
