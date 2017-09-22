#ifndef JXMPP_STREAMMANAGEMENTENABLEDPARSER_H
#define JXMPP_STREAMMANAGEMENTENABLEDPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamManagementEnabled.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API StreamManagementEnabledParser : public GenericElementParser<StreamManagementEnabled> {
        public:
            StreamManagementEnabledParser();
            ~StreamManagementEnabledParser();

            virtual void handleStartElement(const std::string&, const std::string&, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string&);

        private:
            enum Level {
                TopLevel = 0
            };
            int level;
    };
}

#endif // JXMPP_STREAMMANAGEMENTENABLEDPARSER_H
