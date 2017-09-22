#ifndef JXMPP_COMPRESSFAILURESERIALIZER_H
#define JXMPP_COMPRESSFAILURESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CompressFailure.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API CompressFailureSerializer : public GenericElementSerializer<CompressFailure> {
        public:
            CompressFailureSerializer() : GenericElementSerializer<CompressFailure>() {
            }

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const {
                return createSafeByteArray(XMLElement("failure", "http://jabber.org/protocol/compress").serialize());
            }
    };
}

#endif // JXMPP_COMPRESSFAILURESERIALIZER_H
