#include <JXMPP/Serializer/PayloadSerializers/MAMResultSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/ForwardedSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

MAMResultSerializer::MAMResultSerializer(PayloadSerializerCollection* serializers) : serializers_(serializers) {
}

MAMResultSerializer::~MAMResultSerializer() {
}

std::string MAMResultSerializer::serializePayload(std::shared_ptr<MAMResult> payload) const {
    if (!payload) {
        return "";
    }

    XMLElement element("result", "urn:xmpp:mam:0");

    element.setAttribute("id", payload->getID());

    if (payload->getQueryID()) {
        element.setAttribute("queryid", *payload->getQueryID());
    }

    element.addNode(std::make_shared<XMLRawTextNode>(ForwardedSerializer(serializers_).serialize(payload->getPayload())));

    return element.serialize();
}
