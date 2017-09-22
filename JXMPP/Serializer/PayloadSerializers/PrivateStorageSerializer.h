#ifndef JXMPP_PRIVATESTORAGESERIALIZER_H
#define JXMPP_PRIVATESTORAGESERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PrivateStorage.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PrivateStorageSerializer : public GenericPayloadSerializer<PrivateStorage> {
        public:
            PrivateStorageSerializer(PayloadSerializerCollection* serializers);

            virtual std::string serializePayload(std::shared_ptr<PrivateStorage>)  const;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PRIVATESTORAGESERIALIZER_H
