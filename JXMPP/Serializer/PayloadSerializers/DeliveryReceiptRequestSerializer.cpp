/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the BSD license.
 * See http://www.opensource.org/licenses/bsd-license.php for more information.
 */


#include <JXMPP/Serializer/PayloadSerializers/DeliveryReceiptRequestSerializer.h>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {

DeliveryReceiptRequestSerializer::DeliveryReceiptRequestSerializer() : GenericPayloadSerializer<DeliveryReceiptRequest>() {
}

std::string DeliveryReceiptRequestSerializer::serializePayload(std::shared_ptr<DeliveryReceiptRequest> /* request*/) const {
    XMLElement requestXML("request", "urn:xmpp:receipts");
    return requestXML.serialize();
}

}
