#ifndef JXMPP_COMPRESSREQUESTSERIALIZER_H
#define JXMPP_COMPRESSREQUESTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Serializer/ElementSerializer.h>

namespace JXMPP {
    class JXMPP_API CompressRequestSerializer : public ElementSerializer {
        public:
            CompressRequestSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element)  const;
            virtual bool canSerialize(std::shared_ptr<ToplevelElement> element) const;
    };
}

#endif // JXMPP_COMPRESSREQUESTSERIALIZER_H
