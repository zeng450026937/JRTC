#ifndef JXMPP_PRIVATESTORAGE_H
#define JXMPP_PRIVATESTORAGE_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PrivateStorage : public Payload {
        public:
            PrivateStorage(std::shared_ptr<Payload> payload = std::shared_ptr<Payload>()) : payload(payload) {
            }

            std::shared_ptr<Payload> getPayload() const {
                return payload;
            }

            void setPayload(std::shared_ptr<Payload> p) {
                payload = p;
            }

        private:
            std::shared_ptr<Payload> payload;
    };
}

#endif // JXMPP_PRIVATESTORAGE_H
