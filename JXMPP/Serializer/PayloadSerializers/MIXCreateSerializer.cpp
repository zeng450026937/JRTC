/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Serializer/PayloadSerializers/MIXCreateSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

MIXCreateSerializer::MIXCreateSerializer() {
}

MIXCreateSerializer::~MIXCreateSerializer() {
}

std::string MIXCreateSerializer::serializePayload(std::shared_ptr<MIXCreate> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("create", "urn:xmpp:mix:0");

    if(payload->getChannel()) {
        element.setAttribute("channel", *payload->getChannel());
    }

    if(payload->getData()) {
        element.addNode(std::make_shared<XMLRawTextNode>(FormSerializer().serialize(payload->getData())));
    }

    return element.serialize();
}
