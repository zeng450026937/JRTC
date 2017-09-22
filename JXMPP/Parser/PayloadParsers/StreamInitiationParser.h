#ifndef JXMPP_STREAMINITIATIONPARSER_H
#define JXMPP_STREAMINITIATIONPARSER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamInitiation.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class FormParserFactory;
    class FormParser;

    class JXMPP_API StreamInitiationParser : public GenericPayloadParser<StreamInitiation> {
        public:
            StreamInitiationParser();
            ~StreamInitiationParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1,
                FileOrFeatureLevel = 2,
                FormOrDescriptionLevel = 3
            };
            int level;
            FormParserFactory* formParserFactory;
            FormParser* formParser;
            bool inFile;
            bool inFeature;
            StreamInitiationFileInfo currentFile;
            std::string currentText;
    };
}

#endif // JXMPP_STREAMINITIATIONPARSER_H
