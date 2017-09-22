#ifndef JXMPP_STANZAACK_H
#define JXMPP_STANZAACK_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API StanzaAck : public ToplevelElement {
        public:
            typedef std::shared_ptr<StanzaAck> ref;

            StanzaAck() : valid(false), handledStanzasCount(0) {}
            StanzaAck(unsigned int handledStanzasCount) : valid(true), handledStanzasCount(handledStanzasCount) {}
            virtual ~StanzaAck();

            unsigned int getHandledStanzasCount() const {
                return handledStanzasCount;
            }

            void setHandledStanzasCount(int i);

            bool isValid() const {
                return valid;
            }

        private:
            bool valid;
            unsigned int handledStanzasCount;
    };
}

#endif // JXMPP_STANZAACK_H
