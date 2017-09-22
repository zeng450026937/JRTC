#ifndef JXMPP_CARBONSRECEIVED_H
#define JXMPP_CARBONSRECEIVED_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Forwarded.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API CarbonsReceived : public Payload {
        public:
            typedef std::shared_ptr<CarbonsReceived> ref;

        public:
            virtual ~CarbonsReceived();
            void setForwarded(std::shared_ptr<Forwarded> forwarded);
            std::shared_ptr<Forwarded> getForwarded() const;

        private:
            std::shared_ptr<Forwarded> forwarded_;
    };
}

#endif // JXMPP_CARBONSRECEIVED_H
