#ifndef JXMPP_JINGLESESSION_H
#define JXMPP_JINGLESESSION_H

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Listenable.h>
#include <JXMPP/Elements/JinglePayload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JingleSessionListener;
    class JingleContentID;

    class JXMPP_API JingleSession : public Listenable<JingleSessionListener> {
        public:
            typedef std::shared_ptr<JingleSession> ref;

            JingleSession(const JID& initiator, const std::string& id);
            virtual ~JingleSession();

            const JID& getInitiator() const {
                return initiator;
            }

            const std::string& getID() const {
                return id;
            }

            virtual void sendInitiate(const JingleContentID&, JingleDescription::ref, JingleTransportPayload::ref) = 0;
            virtual void sendTerminate(JinglePayload::Reason::Type reason) = 0;
            virtual void sendInfo(std::shared_ptr<Payload>) = 0;
            virtual void sendAccept(const JingleContentID&, JingleDescription::ref, JingleTransportPayload::ref = JingleTransportPayload::ref()) = 0;
            virtual std::string sendTransportInfo(const JingleContentID&, JingleTransportPayload::ref) = 0;
            virtual void sendTransportAccept(const JingleContentID&, JingleTransportPayload::ref) = 0;
            virtual void sendTransportReject(const JingleContentID&, JingleTransportPayload::ref) = 0;
            virtual void sendTransportReplace(const JingleContentID&, JingleTransportPayload::ref) = 0;

        private:
            JID initiator;
            std::string id;
            std::vector<JingleSessionListener*> listeners;
    };
}

#endif // JXMPP_JINGLESESSION_H
