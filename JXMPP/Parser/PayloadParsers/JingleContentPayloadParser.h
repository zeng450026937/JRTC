#ifndef JXMPP_JINGLECONTENTPAYLOADPARSER_H
#define JXMPP_JINGLECONTENTPAYLOADPARSER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleContentPayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {

class PayloadParserFactoryCollection;

class JXMPP_API JingleContentPayloadParser : public GenericPayloadParser<JingleContentPayload> {
    public:
        JingleContentPayloadParser(PayloadParserFactoryCollection* factories);

        virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
        virtual void handleEndElement(const std::string& element, const std::string&);
        virtual void handleCharacterData(const std::string& data);

    private:
        PayloadParserFactoryCollection* factories;
        int level;
        std::shared_ptr<PayloadParser> currentPayloadParser;
};

}

#endif // JXMPP_JINGLECONTENTPAYLOADPARSER_H
