#include <JXMPP/Serializer/PayloadSerializers/MAMFinSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/ResultSetSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

MAMFinSerializer::MAMFinSerializer() {
}

MAMFinSerializer::~MAMFinSerializer() {
}

std::string MAMFinSerializer::serializePayload(std::shared_ptr<MAMFin> payload) const {
    if (!payload) {
        return "";
    }

    XMLElement element("fin", "urn:xmpp:mam:0");

    if (payload->isComplete()) {
        element.setAttribute("complete", "true");
    }

    if (!payload->isStable()) {
        element.setAttribute("stable", "false");
    }

    if (payload->getQueryID()) {
        element.setAttribute("queryid", *payload->getQueryID());
    }

    if (payload->getResultSet()) {
        element.addNode(std::make_shared<XMLRawTextNode>(ResultSetSerializer().serialize(payload->getResultSet())));
    }

    return element.serialize();
}
