#include <JXMPP/Serializer/PayloadSerializers/MAMQuerySerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ForwardedSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ResultSetSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

MAMQuerySerializer::MAMQuerySerializer() {
}

MAMQuerySerializer::~MAMQuerySerializer() {
}

std::string MAMQuerySerializer::serializePayload(std::shared_ptr<MAMQuery> payload) const {
    if (!payload) {
        return "";
    }

    XMLElement element("query", "urn:xmpp:mam:0");

    if (payload->getQueryID()) {
        element.setAttribute("queryid", *payload->getQueryID());
    }

    if (payload->getNode()) {
        element.setAttribute("node", *payload->getNode());
    }

    if (payload->getForm()) {
        element.addNode(std::make_shared<XMLRawTextNode>(FormSerializer().serialize(payload->getForm())));
    }

    if (payload->getResultSet()) {
        element.addNode(std::make_shared<XMLRawTextNode>(ResultSetSerializer().serialize(payload->getResultSet())));
    }

    return element.serialize();
}
