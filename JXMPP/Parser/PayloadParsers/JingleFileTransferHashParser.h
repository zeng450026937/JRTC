#ifndef JXMPP_JINGLEFILETRANSFERHASHPARSER_H
#define JXMPP_JINGLEFILETRANSFERHASHPARSER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleFileTransferHash.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {

class JXMPP_API JingleFileTransferHashParser : public GenericPayloadParser<JingleFileTransferHash> {
public:
    JingleFileTransferHashParser();

    virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
    virtual void handleEndElement(const std::string& element, const std::string&);
    virtual void handleCharacterData(const std::string& data);

private:
    int level;
    std::shared_ptr<PayloadParser> currentPayloadParser;
};

}

#endif // JXMPP_JINGLEFILETRANSFERHASHPARSER_H
