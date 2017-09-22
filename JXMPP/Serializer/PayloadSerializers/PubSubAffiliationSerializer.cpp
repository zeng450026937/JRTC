#include <JXMPP/Serializer/PayloadSerializers/PubSubAffiliationSerializer.h>

#include <cassert>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubAffiliationSerializer::PubSubAffiliationSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubAffiliationSerializer::~PubSubAffiliationSerializer() {
}

std::string PubSubAffiliationSerializer::serializePayload(std::shared_ptr<PubSubAffiliation> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("affiliation", "http://jabber.org/protocol/pubsub");
    element.setAttribute("node", payload->getNode());
    element.setAttribute("affiliation", serializeType(payload->getType()));
    return element.serialize();
}

std::string PubSubAffiliationSerializer::serializeType(PubSubAffiliation::Type value) {
    switch (value) {
        case PubSubAffiliation::None: return "none";
        case PubSubAffiliation::Member: return "member";
        case PubSubAffiliation::Outcast: return "outcast";
        case PubSubAffiliation::Owner: return "owner";
        case PubSubAffiliation::Publisher: return "publisher";
        case PubSubAffiliation::PublishOnly: return "publish-only";
    }
    assert(false);
    return "";
}
