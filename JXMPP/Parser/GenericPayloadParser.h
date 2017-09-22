#ifndef JXMPP_GENERICPAYLOADPARSER_H
#define JXMPP_GENERICPAYLOADPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParser.h>

namespace JXMPP {
    /**
     * A generic payload parser for payloads of the given type.
     *
     * This class provides getPayloadInternal() for retrieving the actual
     * payload.
     */
    template<typename PAYLOAD_TYPE>
    class GenericPayloadParser : public PayloadParser {
        public:
            GenericPayloadParser() : PayloadParser() {
                payload_ = std::make_shared<PAYLOAD_TYPE>();
            }

            virtual std::shared_ptr<Payload> getPayload() const {
                return payload_;
            }

            virtual std::shared_ptr<PAYLOAD_TYPE> getPayloadInternal() const {
                return payload_;
            }

        private:
            std::shared_ptr<PAYLOAD_TYPE> payload_;
    };
}

#endif // JXMPP_GENERICPAYLOADPARSER_H
