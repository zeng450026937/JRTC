#ifndef JXMPP_IQSERIALIZER_H
#define JXMPP_IQSERIALIZER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Serializer/GenericStanzaSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API IQSerializer : public GenericStanzaSerializer<IQ> {
        public:
            IQSerializer(PayloadSerializerCollection* payloadSerializers, const boost::optional<std::string>& explicitNS = boost::optional<std::string>()) :
                    GenericStanzaSerializer<IQ>("iq", payloadSerializers, explicitNS) {
            }

        private:
            virtual void setStanzaSpecificAttributesGeneric(
                    std::shared_ptr<IQ> iq,
                    XMLElement& element) const {
                switch (iq->getType()) {
                    case IQ::Get: element.setAttribute("type","get"); break;
                    case IQ::Set: element.setAttribute("type","set"); break;
                    case IQ::Result: element.setAttribute("type","result"); break;
                    case IQ::Error: element.setAttribute("type","error"); break;
                }
            }
    };
}

#endif // JXMPP_IQSERIALIZER_H
