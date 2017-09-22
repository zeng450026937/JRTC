#ifndef JXMPP_MESSAGESERIALIZER_H
#define JXMPP_MESSAGESERIALIZER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/Serializer/GenericStanzaSerializer.h>

namespace JXMPP {
    class XMLElement;

    class JXMPP_API MessageSerializer : public GenericStanzaSerializer<Message> {
        public:
            MessageSerializer(PayloadSerializerCollection* payloadSerializers, const boost::optional<std::string>& explitNS = boost::optional<std::string>());

        private:
            void setStanzaSpecificAttributesGeneric(
                    std::shared_ptr<Message> message,
                    XMLElement& element) const;
    };
}

#endif // JXMPP_MESSAGESERIALIZER_H
