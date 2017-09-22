#include <JXMPP/Serializer/PayloadSerializers/ResultSetSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

ResultSetSerializer::ResultSetSerializer() {
}

ResultSetSerializer::~ResultSetSerializer() {
}

std::string ResultSetSerializer::serializePayload(std::shared_ptr<ResultSet> payload) const {
    if (!payload) {
        return "";
    }

    XMLElement element("set", "http://jabber.org/protocol/rsm");

    if (payload->getMaxItems()) {
        element.addNode(std::make_shared<XMLElement>("max", "", boost::lexical_cast<std::string>(*payload->getMaxItems())));
    }

    if (payload->getCount()) {
        element.addNode(std::make_shared<XMLElement>("count", "", boost::lexical_cast<std::string>(*payload->getCount())));
    }

    if (payload->getIndex()) {
        element.addNode(std::make_shared<XMLElement>("index", "", boost::lexical_cast<std::string>(*payload->getIndex())));
    }

    if (payload->getFirstID()) {
        std::shared_ptr<XMLElement> firstElement = std::make_shared<XMLElement>("first", "", *payload->getFirstID());
        if (payload->getFirstIDIndex()) {
            firstElement->setAttribute("index", boost::lexical_cast<std::string>(*payload->getFirstIDIndex()));
        }
        element.addNode(firstElement);
    }

    if (payload->getLastID()) {
        element.addNode(std::make_shared<XMLElement>("last", "", *payload->getLastID()));
    }

    if (payload->getBefore()) {
        element.addNode(std::make_shared<XMLElement>("before", "", *payload->getBefore()));
    }

    if (payload->getAfter()) {
        element.addNode(std::make_shared<XMLElement>("after", "", *payload->getAfter()));
    }

    return element.serialize();
}
