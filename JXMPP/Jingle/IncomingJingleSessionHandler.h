#ifndef JXMPP_INCOMINGJINGLESESSIONHANDLER_H
#define JXMPP_INCOMINGJINGLESESSIONHANDLER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Jingle/JingleSession.h>

namespace JXMPP {
    class JXMPP_API IncomingJingleSessionHandler {
        public:
            virtual ~IncomingJingleSessionHandler();

            virtual bool handleIncomingJingleSession(JingleSession::ref, const std::vector<JingleContentPayload::ref>& contents, const JID& recipient) = 0;
    };
}

#endif // JXMPP_INCOMINGJINGLESESSIONHANDLER_H
