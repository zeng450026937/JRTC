#include <JXMPP/Serializer/PayloadSerializers/JingleFileTransferFileInfoSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Base/DateTime.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>
#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

JingleFileTransferFileInfoSerializer::JingleFileTransferFileInfoSerializer() {
}

std::string JingleFileTransferFileInfoSerializer::serializePayload(std::shared_ptr<JingleFileTransferFileInfo> fileInfo) const {

    XMLElement fileElement("file", "");

    if (fileInfo->getDate() != stringToDateTime("")) {
        fileElement.addNode(std::make_shared<XMLElement>("date", "", dateTimeToString(fileInfo->getDate())));
    }

    if (!fileInfo->getDescription().empty()) {
        fileElement.addNode(std::make_shared<XMLElement>("desc", "", fileInfo->getDescription()));
    }

    if (!fileInfo->getMediaType().empty()) {
        fileElement.addNode(std::make_shared<XMLElement>("media-type", "", fileInfo->getMediaType()));
    }

    if (!fileInfo->getName().empty()) {
        fileElement.addNode(std::make_shared<XMLElement>("name", "", fileInfo->getName()));
    }

    if (fileInfo->getSupportsRangeRequests()) {
        std::shared_ptr<XMLElement> range = std::make_shared<XMLElement>("range");
        if (fileInfo->getRangeOffset() != 0) {
            range->setAttribute("offset", boost::lexical_cast<std::string>(fileInfo->getRangeOffset()));
        }
        fileElement.addNode(range);
    }

    if (fileInfo->getSize() > 0) {
        fileElement.addNode(std::make_shared<XMLElement>("size", "", boost::lexical_cast<std::string>(fileInfo->getSize())));
    }

    for (const auto& hashElement : fileInfo->getHashes()) {
        std::shared_ptr<XMLElement> hash = std::make_shared<XMLElement>("hash", "urn:xmpp:hashes:1", Base64::encode(hashElement.second));
        hash->setAttribute("algo", hashElement.first);
        fileElement.addNode(hash);
    }

    return fileElement.serialize();
}

}