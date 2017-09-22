#include <JXMPP/Serializer/PayloadSerializers/VCardUpdateSerializer.h>

#include <memory>

#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

VCardUpdateSerializer::VCardUpdateSerializer() : GenericPayloadSerializer<VCardUpdate>() {
}

std::string VCardUpdateSerializer::serializePayload(std::shared_ptr<VCardUpdate> vcardUpdate)    const {
    XMLElement updateElement("x", "vcard-temp:x:update");
    std::shared_ptr<XMLElement> photoElement(new XMLElement("photo"));
    photoElement->addNode(std::make_shared<XMLTextNode>(vcardUpdate->getPhotoHash()));
    updateElement.addNode(photoElement);
    return updateElement.serialize();
}

}
