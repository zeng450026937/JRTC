/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Serializer/PayloadSerializers/StreamInitiationFileInfoSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Base/DateTime.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

StreamInitiationFileInfoSerializer::StreamInitiationFileInfoSerializer() {
}

std::string StreamInitiationFileInfoSerializer::serializePayload(std::shared_ptr<StreamInitiationFileInfo> fileInfo) const {
    XMLElement fileElement("file", "http://jabber.org/protocol/si/profile/file-transfer");

    if (fileInfo->getDate() != stringToDateTime("")) {
        fileElement.setAttribute("date", dateTimeToString(fileInfo->getDate()));
    }
    fileElement.setAttribute("hash", fileInfo->getHash());
    if (fileInfo->getAlgo() != "md5") {
        fileElement.setAttribute("algo", fileInfo->getAlgo());
    }
    if (!fileInfo->getName().empty()) {
        fileElement.setAttribute("name", fileInfo->getName());
    }
    if (fileInfo->getSize() != 0) {
        fileElement.setAttribute("size", boost::lexical_cast<std::string>(fileInfo->getSize()));
    }
    if (!fileInfo->getDescription().empty()) {
        std::shared_ptr<XMLElement> desc = std::make_shared<XMLElement>("desc", "", fileInfo->getDescription());
        fileElement.addNode(desc);
    }
    if (fileInfo->getSupportsRangeRequests()) {
        std::shared_ptr<XMLElement> range = std::make_shared<XMLElement>("range");
        if (fileInfo->getRangeOffset() != 0) {
            range->setAttribute("offset", boost::lexical_cast<std::string>(fileInfo->getRangeOffset()));
        }
        fileElement.addNode(range);
    }
    return fileElement.serialize();
}

}
