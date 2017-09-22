#ifndef JXMPP_CLIENTSTATEPARSER_H
#define JXMPP_CLIENTSTATEPARSER_H

/*
 * Copyright (c) 2017 Tarun Gupta.
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ClientState.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API ClientStateParser : public GenericPayloadParser<ClientState> {
        public:
            ClientStateParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_ = 0;
    };
}

#endif // JXMPP_CLIENTSTATEPARSER_H
