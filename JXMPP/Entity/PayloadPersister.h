#ifndef JXMPP_PAYLOADPERSISTER_H
#define JXMPP_PAYLOADPERSISTER_H

#include <memory>

#include <boost/filesystem/path.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class Payload;
    class PayloadSerializer;
    class PayloadParser;

    class JXMPP_API PayloadPersister {
        public:
            PayloadPersister();
            virtual ~PayloadPersister();

            void savePayload(std::shared_ptr<Payload>, const boost::filesystem::path&);
            std::shared_ptr<Payload> loadPayload(const boost::filesystem::path&);

        protected:

            virtual const PayloadSerializer* getSerializer() const = 0;
            virtual PayloadParser* createParser() const = 0;
    };
}

#endif // JXMPP_PAYLOADPERSISTER_H
