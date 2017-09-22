#ifndef JXMPP_FORWARDED_H
#define JXMPP_FORWARDED_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class Delay;
    class Stanza;

    class JXMPP_API Forwarded : public Payload {
        public:
            typedef std::shared_ptr<Forwarded> ref;

        public:
            virtual ~Forwarded();

            void setDelay(std::shared_ptr<Delay> delay) { delay_ = delay; }
            const std::shared_ptr<Delay>& getDelay() const { return delay_; }

            void setStanza(std::shared_ptr<Stanza> stanza) { stanza_ = stanza; }
            const std::shared_ptr<Stanza>& getStanza() const { return stanza_; }

        private:
            std::shared_ptr<Delay> delay_;
            std::shared_ptr<Stanza> stanza_;
    };
}

#endif // JXMPP_FORWARDED_H
