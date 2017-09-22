#ifndef JXMPP_GENERICSTANZASERIALIZER_H
#define JXMPP_GENERICSTANZASERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Serializer/StanzaSerializer.h>

namespace JXMPP {
    template<typename STANZA_TYPE>
    class JXMPP_API GenericStanzaSerializer : public StanzaSerializer {
        public:
            GenericStanzaSerializer(const std::string& tag, PayloadSerializerCollection* payloadSerializers, const boost::optional<std::string>& explicitNS = boost::optional<std::string>()) : StanzaSerializer(tag, payloadSerializers, explicitNS) {}

            virtual bool canSerialize(std::shared_ptr<ToplevelElement> element) const {
                return dynamic_cast<STANZA_TYPE*>(element.get()) != nullptr;
            }

            virtual void setStanzaSpecificAttributes(
                    std::shared_ptr<ToplevelElement> stanza,
                    XMLElement& element) const {
                setStanzaSpecificAttributesGeneric(
                        std::dynamic_pointer_cast<STANZA_TYPE>(stanza), element);
            }

            virtual void setStanzaSpecificAttributesGeneric(
                    std::shared_ptr<STANZA_TYPE>,
                    XMLElement&) const = 0;
    };
}

#endif // JXMPP_GENERICSTANZASERIALIZER_H
