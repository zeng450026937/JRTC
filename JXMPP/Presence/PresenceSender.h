#ifndef JXMPP_PRESENCESENDER_H
#define JXMPP_PRESENCESENDER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Presence.h>

namespace JXMPP {
    class JXMPP_API PresenceSender {
        public:
            virtual ~PresenceSender();

            virtual void sendPresence(Presence::ref) = 0;

            virtual bool isAvailable() const = 0;
    };
}

#endif // JXMPP_PRESENCESENDER_H
