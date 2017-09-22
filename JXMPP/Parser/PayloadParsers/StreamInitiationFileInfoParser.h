#ifndef JXMPP_STREAMINITIATIONFILEINFOPARSER_H
#define JXMPP_STREAMINITIATIONFILEINFOPARSER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamInitiationFileInfo.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {

class JXMPP_API StreamInitiationFileInfoParser : public GenericPayloadParser<StreamInitiationFileInfo> {
    public:
        StreamInitiationFileInfoParser();

        virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
        virtual void handleEndElement(const std::string& element, const std::string&);
        virtual void handleCharacterData(const std::string& data);

    private:
        int level;
        bool parseDescription;
        std::string desc;
};

}

#endif // JXMPP_STREAMINITIATIONFILEINFOPARSER_H
