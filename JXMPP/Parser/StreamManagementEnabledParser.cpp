#include <JXMPP/Parser/StreamManagementEnabledParser.h>

using namespace JXMPP;

StreamManagementEnabledParser::StreamManagementEnabledParser() : level(TopLevel) {
}

StreamManagementEnabledParser::~StreamManagementEnabledParser() {
}

void StreamManagementEnabledParser::handleStartElement(const std::string&, const std::string&, const AttributeMap& attributes) {
    if (level == TopLevel) {
        if (attributes.getBoolAttribute("resume", false)) {
            getElementGeneric()->setResumeSupported();
        }
        getElementGeneric()->setResumeID(attributes.getAttribute("id"));
    }
    ++level;
}

void StreamManagementEnabledParser::handleEndElement(const std::string&, const std::string&) {
    --level;
}
