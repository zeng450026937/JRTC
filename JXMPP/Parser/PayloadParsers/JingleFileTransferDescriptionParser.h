#ifndef JXMPP_JINGLEFILETRANSFERDESCRIPTIONPARSER_H
#define JXMPP_JINGLEFILETRANSFERDESCRIPTIONPARSER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleFileTransferDescription.h>
#include <JXMPP/Parser/GenericPayloadParser.h>
#include <JXMPP/Parser/PayloadParser.h>

namespace JXMPP {

class PayloadParserFactoryCollection;

class JXMPP_API JingleFileTransferDescriptionParser : public GenericPayloadParser<JingleFileTransferDescription> {
    public:
        JingleFileTransferDescriptionParser(PayloadParserFactoryCollection* factories);

        virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
        virtual void handleEndElement(const std::string& element, const std::string&);
        virtual void handleCharacterData(const std::string& data);

    private:
        PayloadParserFactoryCollection* factories;
        int level;
        std::shared_ptr<PayloadParser> currentPayloadParser;
};

}

#endif // JXMPP_JINGLEFILETRANSFERDESCRIPTIONPARSER_H
