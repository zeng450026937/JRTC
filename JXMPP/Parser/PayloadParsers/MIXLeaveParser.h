#ifndef JXMPP_MIXLEAVEPARSER_H
#define JXMPP_MIXLEAVEPARSER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXLeave.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {

    class JXMPP_API MIXLeaveParser : public GenericPayloadParser<MIXLeave> {
        public:
            MIXLeaveParser();
            virtual ~MIXLeaveParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level_;
    };
}

#endif // JXMPP_MIXLEAVEPARSER_H
