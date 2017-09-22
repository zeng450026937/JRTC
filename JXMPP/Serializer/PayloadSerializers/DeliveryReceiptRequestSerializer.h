#ifndef JXMPP_DELIVERYRECEIPTREQUESTSERIALIZER_H
#define JXMPP_DELIVERYRECEIPTREQUESTSERIALIZER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the BSD license.
 * See http://www.opensource.org/licenses/bsd-license.php for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DeliveryReceiptRequest.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API DeliveryReceiptRequestSerializer : public GenericPayloadSerializer<DeliveryReceiptRequest> {
        public:
            DeliveryReceiptRequestSerializer();

            virtual std::string serializePayload(std::shared_ptr<DeliveryReceiptRequest> request) const;
    };
}

#endif // JXMPP_DELIVERYRECEIPTREQUESTSERIALIZER_H
