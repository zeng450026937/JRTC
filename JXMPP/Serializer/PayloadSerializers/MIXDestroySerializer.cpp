/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Serializer/PayloadSerializers/MIXDestroySerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

MIXDestroySerializer::MIXDestroySerializer() {
}

MIXDestroySerializer::~MIXDestroySerializer() {
}

std::string MIXDestroySerializer::serializePayload(std::shared_ptr<MIXDestroy> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("destroy", "urn:xmpp:mix:0");
    element.setAttribute("channel", payload->getChannel());
    return element.serialize();
}
