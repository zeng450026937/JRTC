#ifndef JXMPP_JINGLERESPONDER_H
#define JXMPP_JINGLERESPONDER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JinglePayload.h>
#include <JXMPP/Queries/SetResponder.h>

namespace JXMPP {
    class IQRouter;
    class JingleSessionManager;

    class JXMPP_API JingleResponder : public SetResponder<JinglePayload> {
        public:
            JingleResponder(JingleSessionManager* sessionManager, IQRouter* router);
            virtual ~JingleResponder();
        private:
            virtual bool handleSetRequest(const JID& from, const JID& to, const std::string& id, std::shared_ptr<JinglePayload> payload);

        private:
            JingleSessionManager* sessionManager;
            IQRouter* router;
    };
}

#endif // JXMPP_JINGLERESPONDER_H
