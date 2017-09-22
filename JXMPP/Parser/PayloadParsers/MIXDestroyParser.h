#ifndef JXMPP_MIXDESTROYPARSER_H
#define JXMPP_MIXDESTROYPARSER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXDestroy.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParser;

    class JXMPP_API MIXDestroyParser : public GenericPayloadParser<MIXDestroy> {
        public:
            MIXDestroyParser();
            virtual ~MIXDestroyParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level_;
    };
}

#endif // JXMPP_MIXDESTROYPARSER_H
