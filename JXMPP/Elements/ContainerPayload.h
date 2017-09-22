#ifndef JXMPP_CONTAINERPAYLOAD_H
#define JXMPP_CONTAINERPAYLOAD_H

#include <memory>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    template<typename T>
    class JXMPP_API ContainerPayload : public Payload {
        public:
            ContainerPayload() {}
            ContainerPayload(std::shared_ptr<T> payload) : payload(payload) {}

            void setPayload(std::shared_ptr<T> payload) {
                this->payload = payload;
            }

            std::shared_ptr<T> getPayload() const {
                return payload;
            }

        private:
            std::shared_ptr<T> payload;
    };
}

#endif // JXMPP_CONTAINERPAYLOAD_H
