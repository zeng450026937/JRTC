#ifndef JXMPP_DELIVERYRECEIPTPARSERFACTORY_H
#define JXMPP_DELIVERYRECEIPTPARSERFACTORY_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the BSD license.
 * See http://www.opensource.org/licenses/bsd-license.php for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/DeliveryReceiptParser.h>

namespace JXMPP {
    class JXMPP_API DeliveryReceiptParserFactory : public PayloadParserFactory {
        public:
            DeliveryReceiptParserFactory() {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return ns == "urn:xmpp:receipts" && element == "received";
            }

            virtual PayloadParser* createPayloadParser() {
                return new DeliveryReceiptParser();
            }

    };
}

#endif // JXMPP_DELIVERYRECEIPTPARSERFACTORY_H
