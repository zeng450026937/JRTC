#ifndef JXMPP_PRESENCESERIALIZER_H
#define JXMPP_PRESENCESERIALIZER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/Serializer/GenericStanzaSerializer.h>

namespace JXMPP {
    class JXMPP_API PresenceSerializer : public GenericStanzaSerializer<Presence> {
        public:
            PresenceSerializer(PayloadSerializerCollection* payloadSerializers, const boost::optional<std::string>& explicitNS = boost::optional<std::string>());
            ~PresenceSerializer() {}

        private:
            virtual void setStanzaSpecificAttributesGeneric(
                    std::shared_ptr<Presence> presence,
                    XMLElement& element) const;
    };
}

#endif // JXMPP_PRESENCESERIALIZER_H
