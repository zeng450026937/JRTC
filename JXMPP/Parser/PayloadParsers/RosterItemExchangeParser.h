#ifndef JXMPP_ROSTERITEMEXCHANGEPARSER_H
#define JXMPP_ROSTERITEMEXCHANGEPARSER_H

/*
 * Copyright (c) 2011 Jan Kaluza
 * Licensed under the Simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RosterItemExchangePayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API RosterItemExchangeParser : public GenericPayloadParser<RosterItemExchangePayload> {
        public:
            RosterItemExchangeParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1,
                ItemLevel = 2
            };
            int level_;
            bool inItem_;
            RosterItemExchangePayload::Item currentItem_;
            std::string currentText_;
    };
}

#endif // JXMPP_ROSTERITEMEXCHANGEPARSER_H
