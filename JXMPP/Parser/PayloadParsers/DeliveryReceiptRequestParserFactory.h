#ifndef JXMPP_DELIVERYRECEIPTREQUESTPARSERFACTORY_H
#define JXMPP_DELIVERYRECEIPTREQUESTPARSERFACTORY_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the BSD license.
 * See http://www.opensource.org/licenses/bsd-license.php for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/DeliveryReceiptRequestParser.h>

namespace JXMPP {
    class JXMPP_API DeliveryReceiptRequestParserFactory : public PayloadParserFactory {
        public:
            DeliveryReceiptRequestParserFactory() {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return ns == "urn:xmpp:receipts" && element == "request";
            }

            virtual PayloadParser* createPayloadParser() {
                return new DeliveryReceiptRequestParser();
            }

    };
}

#endif // JXMPP_DELIVERYRECEIPTREQUESTPARSERFACTORY_H
