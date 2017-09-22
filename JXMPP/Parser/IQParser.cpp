#include <JXMPP/Parser/IQParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Base/Log.h>

namespace JXMPP {

IQParser::IQParser(PayloadParserFactoryCollection* factories) :
        GenericStanzaParser<IQ>(factories) {
}

void IQParser::handleStanzaAttributes(const AttributeMap& attributes) {
    boost::optional<std::string> type = attributes.getAttributeValue("type");
    if (type) {
        if (*type == "set") {
            getStanzaGeneric()->setType(IQ::Set);
        }
        else if (*type == "get") {
            getStanzaGeneric()->setType(IQ::Get);
        }
        else if (*type == "result") {
            getStanzaGeneric()->setType(IQ::Result);
        }
        else if (*type == "error") {
            getStanzaGeneric()->setType(IQ::Error);
        }
        else {
            JXMPP_LOG(warning) << "Unknown IQ type: " << *type << std::endl;
            getStanzaGeneric()->setType(IQ::Get);
        }
    }
}

}
