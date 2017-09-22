#ifndef JXMPP_DELIVERYRECEIPTREQUESTPARSER_H
#define JXMPP_DELIVERYRECEIPTREQUESTPARSER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the BSD license.
 * See http://www.opensource.org/licenses/bsd-license.php for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DeliveryReceiptRequest.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API DeliveryReceiptRequestParser : public GenericPayloadParser<DeliveryReceiptRequest> {
        public:
            DeliveryReceiptRequestParser();

            virtual void handleStartElement(const std::string&, const std::string&, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string&);
            virtual void handleCharacterData(const std::string& data);
    };
}

#endif // JXMPP_DELIVERYRECEIPTREQUESTPARSER_H
