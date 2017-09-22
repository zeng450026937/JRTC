#ifndef JXMPP_STREAMFEATURESPARSER_H
#define JXMPP_STREAMFEATURESPARSER_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamFeatures.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API StreamFeaturesParser : public GenericElementParser<StreamFeatures> {
        public:
            StreamFeaturesParser();

        private:
            void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes);
            void handleEndElement(const std::string& element, const std::string& ns);
            void handleCharacterData(const std::string& data);

        private:
            int currentDepth_;
            std::string currentText_;
            bool inMechanisms_;
            bool inMechanism_;
            bool inAuthenticationHostname_;
            bool inCompression_;
            bool inCompressionMethod_;
    };
}

#endif // JXMPP_STREAMFEATURESPARSER_H
