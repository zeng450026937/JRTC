/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Serializer/PayloadSerializers/MIXUserPreferenceSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

namespace JXMPP {

MIXUserPreferenceSerializer::MIXUserPreferenceSerializer() {
}

MIXUserPreferenceSerializer::~MIXUserPreferenceSerializer() {
}

std::string MIXUserPreferenceSerializer::serializePayload(std::shared_ptr<MIXUserPreference> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("user-preference", "urn:xmpp:mix:0");
    if(payload->getData()) {
        element.addNode(std::make_shared<XMLRawTextNode>(FormSerializer().serialize(payload->getData())));
    }
    return element.serialize();
}
}
