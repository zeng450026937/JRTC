/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Serializer/PayloadSerializers/JingleIBBTransportPayloadSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLNode.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

namespace JXMPP {

JingleIBBTransportPayloadSerializer::JingleIBBTransportPayloadSerializer() {
}

std::string JingleIBBTransportPayloadSerializer::serializePayload(std::shared_ptr<JingleIBBTransportPayload> payload) const {
    XMLElement payloadXML("transport", "urn:xmpp:jingle:transports:ibb:1");
    if (payload->getBlockSize()) {
        payloadXML.setAttribute("block-size", boost::lexical_cast<std::string>(*payload->getBlockSize()));
    }
    payloadXML.setAttribute("sid", payload->getSessionID());

    return payloadXML.serialize();
}

}
