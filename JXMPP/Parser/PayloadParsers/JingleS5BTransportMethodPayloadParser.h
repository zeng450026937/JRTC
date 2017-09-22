#ifndef JXMPP_JINGLES5BTRANSPORTMETHODPAYLOADPARSER_H
#define JXMPP_JINGLES5BTRANSPORTMETHODPAYLOADPARSER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleS5BTransportPayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {

class JXMPP_API JingleS5BTransportMethodPayloadParser : public GenericPayloadParser<JingleS5BTransportPayload> {
    public:
        JingleS5BTransportMethodPayloadParser();

        virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
        virtual void handleEndElement(const std::string& element, const std::string&);
        virtual void handleCharacterData(const std::string& data);

    private:
        JingleS5BTransportPayload::Candidate::Type stringToType(const std::string &str) const;

    private:
        int level;
};

}

#endif // JXMPP_JINGLES5BTRANSPORTMETHODPAYLOADPARSER_H
