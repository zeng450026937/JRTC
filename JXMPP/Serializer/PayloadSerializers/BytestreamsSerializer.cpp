#include <JXMPP/Serializer/PayloadSerializers/BytestreamsSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {

BytestreamsSerializer::BytestreamsSerializer() {
}

std::string BytestreamsSerializer::serializePayload(std::shared_ptr<Bytestreams> bytestreams)    const {
    XMLElement queryElement("query", "http://jabber.org/protocol/bytestreams");
    queryElement.setAttribute("sid", bytestreams->getStreamID());
    for (const auto& streamHost : bytestreams->getStreamHosts()) {
        std::shared_ptr<XMLElement> streamHostElement(new XMLElement("streamhost"));
        streamHostElement->setAttribute("host", streamHost.host);
        streamHostElement->setAttribute("jid", streamHost.jid.toString());
        streamHostElement->setAttribute("port", boost::lexical_cast<std::string>(streamHost.port));
        queryElement.addNode(streamHostElement);
    }

    if (bytestreams->getUsedStreamHost()) {
        std::shared_ptr<XMLElement> streamHostElement(new XMLElement("streamhost-used"));
        streamHostElement->setAttribute("jid", *bytestreams->getUsedStreamHost());
        queryElement.addNode(streamHostElement);
    }
    return queryElement.serialize();
}

}
