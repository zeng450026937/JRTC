#ifndef JXMPP_STANZAACKRESPONDER_H
#define JXMPP_STANZAACKRESPONDER_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Stanza.h>

namespace JXMPP {
    class JXMPP_API StanzaAckResponder {
        public:
            StanzaAckResponder();

            void handleStanzaReceived();
            void handleAckRequestReceived();

        public:
            boost::signals2::signal<void (unsigned int /* handledStanzaCount */)> onAck;

        private:
            friend class StanzaAckResponderTest;
            unsigned int handledStanzasCount;
    };

}

#endif // JXMPP_STANZAACKRESPONDER_H
