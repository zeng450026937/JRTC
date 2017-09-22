#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerAffiliationSerializer.h>

#include <cassert>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubOwnerAffiliationSerializer::PubSubOwnerAffiliationSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubOwnerAffiliationSerializer::~PubSubOwnerAffiliationSerializer() {
}

std::string PubSubOwnerAffiliationSerializer::serializePayload(std::shared_ptr<PubSubOwnerAffiliation> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("affiliation", "http://jabber.org/protocol/pubsub#owner");
    element.setAttribute("jid", payload->getJID());
    element.setAttribute("affiliation", serializeType(payload->getType()));
    return element.serialize();
}

std::string PubSubOwnerAffiliationSerializer::serializeType(PubSubOwnerAffiliation::Type value) {
    switch (value) {
        case PubSubOwnerAffiliation::None: return "none";
        case PubSubOwnerAffiliation::Member: return "member";
        case PubSubOwnerAffiliation::Outcast: return "outcast";
        case PubSubOwnerAffiliation::Owner: return "owner";
        case PubSubOwnerAffiliation::Publisher: return "publisher";
        case PubSubOwnerAffiliation::PublishOnly: return "publish-only";
    }
    assert(false);
    return "";
}
