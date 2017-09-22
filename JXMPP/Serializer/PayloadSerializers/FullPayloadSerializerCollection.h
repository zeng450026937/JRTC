#ifndef JXMPP_FULLPAYLOADSERIALIZERCOLLECTION_H
#define JXMPP_FULLPAYLOADSERIALIZERCOLLECTION_H

#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Serializer/PayloadSerializerCollection.h>

namespace JXMPP {
    class JXMPP_API FullPayloadSerializerCollection : public PayloadSerializerCollection {
        public:
            FullPayloadSerializerCollection();
            virtual ~FullPayloadSerializerCollection();

        private:
            std::vector<PayloadSerializer*> serializers_;
    };
}

#endif // JXMPP_FULLPAYLOADSERIALIZERCOLLECTION_H
