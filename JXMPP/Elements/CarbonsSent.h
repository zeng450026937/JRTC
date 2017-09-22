#ifndef JXMPP_CARBONSSENT_H
#define JXMPP_CARBONSSENT_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Forwarded.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API CarbonsSent : public Payload {
        public:
            typedef std::shared_ptr<CarbonsSent> ref;

        public:
            virtual ~CarbonsSent();
            void setForwarded(std::shared_ptr<Forwarded> forwarded);
            std::shared_ptr<Forwarded> getForwarded() const;

        private:
            std::shared_ptr<Forwarded> forwarded_;
    };
}

#endif // JXMPP_CARBONSSENT_H
