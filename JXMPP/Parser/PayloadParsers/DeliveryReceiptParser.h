#ifndef JXMPP_DELIVERYRECEIPTPARSER_H
#define JXMPP_DELIVERYRECEIPTPARSER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the BSD license.
 * See http://www.opensource.org/licenses/bsd-license.php for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DeliveryReceipt.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API DeliveryReceiptParser : public GenericPayloadParser<DeliveryReceipt> {
        public:
            DeliveryReceiptParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributeMap);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
    };
}

#endif // JXMPP_DELIVERYRECEIPTPARSER_H
