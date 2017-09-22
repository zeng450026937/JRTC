#ifndef JXMPP_DELIVERYRECEIPT_H
#define JXMPP_DELIVERYRECEIPT_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the BSD license.
 * See http://www.opensource.org/licenses/bsd-license.php for more information.
 */




#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {

class JXMPP_API DeliveryReceipt : public Payload {
    public:
        typedef std::shared_ptr<DeliveryReceipt> ref;

    public:
        DeliveryReceipt() {}

        DeliveryReceipt(const std::string& msgId) : receivedID_(msgId) {}

        void setReceivedID(const std::string& msgId) {
            receivedID_ = msgId;
        }

        std::string getReceivedID() const {
            return receivedID_;
        }

    private:
        std::string receivedID_;
};

}

#endif // JXMPP_DELIVERYRECEIPT_H
