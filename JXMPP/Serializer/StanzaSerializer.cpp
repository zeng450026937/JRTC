#include <JXMPP/Serializer/StanzaSerializer.h>

#include <sstream>
#include <typeinfo>

#include <JXMPP/Base/String.h>
#include <JXMPP/Base/Log.h>
#include <JXMPP/Elements/Stanza.h>
#include <JXMPP/Serializer/PayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

namespace JXMPP {

StanzaSerializer::StanzaSerializer(const std::string& tag, PayloadSerializerCollection* payloadSerializers, const boost::optional<std::string>& explicitNS) : tag_(tag), payloadSerializers_(payloadSerializers), explicitDefaultNS_(explicitNS) {
}

SafeByteArray StanzaSerializer::serialize(std::shared_ptr<ToplevelElement> element) const {
    if (explicitDefaultNS_) {
        return serialize(element, explicitDefaultNS_.get());
    }
    else {
        return serialize(element, "");
    }
}

SafeByteArray StanzaSerializer::serialize(std::shared_ptr<ToplevelElement> element, const std::string& xmlns) const {
    std::shared_ptr<Stanza> stanza(std::dynamic_pointer_cast<Stanza>(element));

    XMLElement stanzaElement(tag_, explicitDefaultNS_ ? explicitDefaultNS_.get() : xmlns);
    if (stanza->getFrom().isValid()) {
        stanzaElement.setAttribute("from", stanza->getFrom());
    }
    if (stanza->getTo().isValid()) {
        stanzaElement.setAttribute("to", stanza->getTo());
    }
    if (!stanza->getID().empty()) {
        stanzaElement.setAttribute("id", stanza->getID());
    }
    setStanzaSpecificAttributes(stanza, stanzaElement);

    std::string serializedPayloads;
    for (const auto& payload : stanza->getPayloads()) {
        PayloadSerializer* serializer = payloadSerializers_->getPayloadSerializer(payload);
        if (serializer) {
            serializedPayloads += serializer->serialize(payload);
        }
        else {
            JXMPP_LOG(warning) << "Could not find serializer for " << typeid(*(payload.get())).name() << std::endl;
        }
    }
    serializedPayloads = String::sanitizeXMPPString(serializedPayloads);
    if (!serializedPayloads.empty()) {
        stanzaElement.addNode(std::make_shared<XMLRawTextNode>(serializedPayloads));
    }

    return createSafeByteArray(stanzaElement.serialize());
}

}
