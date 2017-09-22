#ifndef JXMPP_S5BPROXYREQUESTPARSER_H
#define JXMPP_S5BPROXYREQUESTPARSER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/S5BProxyRequest.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {

class JXMPP_API S5BProxyRequestParser : public GenericPayloadParser<S5BProxyRequest> {
public:
    S5BProxyRequestParser();
    virtual ~S5BProxyRequestParser();

    virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
    virtual void handleEndElement(const std::string& element, const std::string&);
    virtual void handleCharacterData(const std::string& data);

private:
    bool parseActivate;
    std::string activateJID;
};

}

#endif // JXMPP_S5BPROXYREQUESTPARSER_H
