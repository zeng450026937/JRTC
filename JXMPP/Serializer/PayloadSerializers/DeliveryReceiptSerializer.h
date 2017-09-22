#ifndef JXMPP_DELIVERYRECEIPTSERIALIZER_H
#define JXMPP_DELIVERYRECEIPTSERIALIZER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the BSD license.
 * See http://www.opensource.org/licenses/bsd-license.php for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DeliveryReceipt.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API DeliveryReceiptSerializer : public GenericPayloadSerializer<DeliveryReceipt> {
        public:
            DeliveryReceiptSerializer();

            virtual std::string serializePayload(std::shared_ptr<DeliveryReceipt> receipt) const;
    };
}

#endif // JXMPP_DELIVERYRECEIPTSERIALIZER_H
