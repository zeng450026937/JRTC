#ifndef JXMPP_STANZAACKREQUESTER_H
#define JXMPP_STANZAACKREQUESTER_H

#include <deque>
#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Stanza.h>

namespace JXMPP {
    class JXMPP_API StanzaAckRequester {
        public:
            StanzaAckRequester();

            void handleStanzaSent(std::shared_ptr<Stanza> stanza);
            void handleAckReceived(unsigned int handledStanzasCount);

        public:
            boost::signals2::signal<void ()> onRequestAck;
            boost::signals2::signal<void (std::shared_ptr<Stanza>)> onStanzaAcked;

        private:
            friend class StanzaAckRequesterTest;
            unsigned int lastHandledStanzasCount;
            std::deque<std::shared_ptr<Stanza> > unackedStanzas;
    };

}

#endif // JXMPP_STANZAACKREQUESTER_H
