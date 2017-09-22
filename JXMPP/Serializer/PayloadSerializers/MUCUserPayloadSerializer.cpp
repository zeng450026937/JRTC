#include <JXMPP/Serializer/PayloadSerializers/MUCUserPayloadSerializer.h>

#include <memory>
#include <sstream>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/MUCItemSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

MUCUserPayloadSerializer::MUCUserPayloadSerializer(PayloadSerializerCollection* serializers) : GenericPayloadSerializer<MUCUserPayload>(), serializers(serializers) {
}

std::string MUCUserPayloadSerializer::serializePayload(std::shared_ptr<MUCUserPayload> payload)  const {
    XMLElement mucElement("x", "http://jabber.org/protocol/muc#user");
    for (const auto& statusCode : payload->getStatusCodes()) {
        std::shared_ptr<XMLElement> statusElement(new XMLElement("status"));
        std::ostringstream code;
        code << statusCode.code;
        statusElement->setAttribute("code", code.str());
        mucElement.addNode(statusElement);
    }
    for (const auto& item : payload->getItems()) {
        mucElement.addNode(MUCItemSerializer::itemToElement(item));
    }

    if (payload->getPassword()) {
        std::shared_ptr<XMLElement> passwordElement = std::make_shared<XMLElement>("password");
        passwordElement->addNode(std::make_shared<XMLTextNode>(*payload->getPassword()));
    }

    if (payload->getInvite()) {
        MUCUserPayload::Invite invite = *payload->getInvite();
        std::shared_ptr<XMLElement> inviteElement = std::make_shared<XMLElement>("invite");
        if (invite.to.isValid()) {
            inviteElement->setAttribute("to", invite.to.toString());
        }
        if (invite.from.isValid()) {
            inviteElement->setAttribute("from", invite.from.toString());
        }
        if (!invite.reason.empty()) {
            std::shared_ptr<XMLElement> reasonElement = std::make_shared<XMLElement>("reason");
            reasonElement->addNode(std::make_shared<XMLTextNode>(invite.reason));
        }
        mucElement.addNode(inviteElement);
    }

    std::shared_ptr<Payload> childPayload = payload->getPayload();
    if (childPayload) {
        PayloadSerializer* serializer = serializers->getPayloadSerializer(childPayload);
        if (serializer) {
            mucElement.addNode(std::make_shared<XMLRawTextNode>(serializer->serialize(childPayload)));
        }
    }
    return mucElement.serialize();
}




}
