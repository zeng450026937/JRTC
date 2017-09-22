#ifndef JXMPP_STANZASERIALIZER_H
#define JXMPP_STANZASERIALIZER_H

#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Stanza.h>
#include <JXMPP/Serializer/ElementSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;
    class XMLElement;

    class JXMPP_API StanzaSerializer : public ElementSerializer {
        public:
            StanzaSerializer(const std::string& tag, PayloadSerializerCollection* payloadSerializers, const boost::optional<std::string>& explicitNS = boost::optional<std::string>());

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element) const;
            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element, const std::string& xmlns) const;
            virtual void setStanzaSpecificAttributes(std::shared_ptr<ToplevelElement>, XMLElement&) const = 0;

        private:
            std::string tag_;
            PayloadSerializerCollection* payloadSerializers_;
            boost::optional<std::string> explicitDefaultNS_;
    };
}

#endif // JXMPP_STANZASERIALIZER_H
