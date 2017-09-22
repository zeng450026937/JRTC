#ifndef JXMPP_ISODEIQDELEGATION_H
#define JXMPP_ISODEIQDELEGATION_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Forwarded.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API IsodeIQDelegation : public Payload {
        public:

            IsodeIQDelegation();

            virtual ~IsodeIQDelegation();

            std::shared_ptr<Forwarded> getForward() const {
                return forward;
            }

            void setForward(std::shared_ptr<Forwarded> value) {
                this->forward = value ;
            }


        private:
            std::shared_ptr<Forwarded> forward;
    };
}

#endif // JXMPP_ISODEIQDELEGATION_H
