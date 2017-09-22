#ifndef JXMPP_PAYLOADSERIALIZERCOLLECTION_H
#define JXMPP_PAYLOADSERIALIZERCOLLECTION_H

#include <memory>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class PayloadSerializer;

    class JXMPP_API PayloadSerializerCollection {
        public:
            PayloadSerializerCollection();
            virtual ~PayloadSerializerCollection();

            void addSerializer(PayloadSerializer* factory);
            void removeSerializer(PayloadSerializer* factory);
            PayloadSerializer* getPayloadSerializer(std::shared_ptr<Payload>) const;

        private:
            std::vector<PayloadSerializer*> serializers_;
    };
}

#endif // JXMPP_PAYLOADSERIALIZERCOLLECTION_H
