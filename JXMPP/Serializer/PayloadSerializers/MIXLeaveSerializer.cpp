/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Serializer/PayloadSerializers/MIXLeaveSerializer.h>

#include <memory>

#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {

MIXLeaveSerializer::MIXLeaveSerializer() {
}

MIXLeaveSerializer::~MIXLeaveSerializer() {
}

std::string MIXLeaveSerializer::serializePayload(std::shared_ptr<MIXLeave> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("leave", "urn:xmpp:mix:0");
    if (payload->getChannel()) {
        element.setAttribute("channel", *payload->getChannel());
    }
    return element.serialize();
}
}
