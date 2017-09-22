#ifndef JXMPP_DELIVERYRECEIPTREQUEST_H
#define JXMPP_DELIVERYRECEIPTREQUEST_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the BSD license.
 * See http://www.opensource.org/licenses/bsd-license.php for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {

class JXMPP_API DeliveryReceiptRequest : public Payload {
    public:
        typedef std::shared_ptr<DeliveryReceiptRequest> ref;

    public:
        DeliveryReceiptRequest() {}
};

}

#endif // JXMPP_DELIVERYRECEIPTREQUEST_H
