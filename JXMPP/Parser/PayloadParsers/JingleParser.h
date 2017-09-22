#ifndef JXMPP_JINGLEPARSER_H
#define JXMPP_JINGLEPARSER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JinglePayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>

namespace JXMPP {

class JXMPP_API JingleParser : public GenericPayloadParser<JinglePayload> {
        public:
            JingleParser(PayloadParserFactoryCollection* factories);

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            JinglePayload::Action stringToAction(const std::string &str) const;

        private:
            PayloadParserFactoryCollection* factories;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
};

}

#endif // JXMPP_JINGLEPARSER_H
