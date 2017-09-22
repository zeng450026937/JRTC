#ifndef JXMPP_GENERICPAYLOADPERSISTER_H
#define JXMPP_GENERICPAYLOADPERSISTER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Entity/PayloadPersister.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>

namespace JXMPP {
    template<typename PAYLOAD, typename PARSER, typename SERIALIZER>
    class JXMPP_API GenericPayloadPersister : public PayloadPersister {
        public:
            GenericPayloadPersister() {
            }

        public:
            std::shared_ptr<PAYLOAD> loadPayloadGeneric(const boost::filesystem::path& path) {
                return std::dynamic_pointer_cast<PAYLOAD>(loadPayload(path));
            }

        protected:
            virtual const PayloadSerializer* getSerializer() const {
                return &serializer;
            }

            virtual PayloadParser* createParser() const {
                return new PARSER();
            }

        private:
            SERIALIZER serializer;
    };
}

#endif // JXMPP_GENERICPAYLOADPERSISTER_H
