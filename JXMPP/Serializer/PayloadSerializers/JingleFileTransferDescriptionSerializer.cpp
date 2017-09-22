/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Serializer/PayloadSerializers/JingleFileTransferDescriptionSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Base/DateTime.h>
#include <JXMPP/Serializer/PayloadSerializers/JingleFileTransferFileInfoSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLNode.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>
#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

JingleFileTransferDescriptionSerializer::JingleFileTransferDescriptionSerializer() {
}

std::string JingleFileTransferDescriptionSerializer::serializePayload(std::shared_ptr<JingleFileTransferDescription> payload) const {
    XMLElement description("description", "urn:xmpp:jingle:apps:file-transfer:4");

    JingleFileTransferFileInfoSerializer fileInfoSerializer;
    std::shared_ptr<XMLRawTextNode> fileInfoXML = std::make_shared<XMLRawTextNode>(fileInfoSerializer.serialize(std::make_shared<JingleFileTransferFileInfo>(payload->getFileInfo())));
    description.addNode(fileInfoXML);
    return description.serialize();
}

}
