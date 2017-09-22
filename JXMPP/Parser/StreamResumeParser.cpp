#include <JXMPP/Parser/StreamResumeParser.h>

#include <boost/lexical_cast.hpp>

using namespace JXMPP;

StreamResumeParser::StreamResumeParser() : level(TopLevel) {
}

StreamResumeParser::~StreamResumeParser() {
}

void StreamResumeParser::handleStartElement(const std::string&, const std::string&, const AttributeMap& attributes) {
    if (level == TopLevel) {
        boost::optional<std::string> handledStanzasCount = attributes.getAttributeValue("h");
        if (handledStanzasCount) {
            try {
                getElementGeneric()->setHandledStanzasCount(boost::lexical_cast<unsigned int>(*handledStanzasCount));
            }
            catch (const boost::bad_lexical_cast &) {
            }
        }
        getElementGeneric()->setResumeID(attributes.getAttribute("previd"));
    }
    ++level;
}

void StreamResumeParser::handleEndElement(const std::string&, const std::string&) {
    --level;
}
