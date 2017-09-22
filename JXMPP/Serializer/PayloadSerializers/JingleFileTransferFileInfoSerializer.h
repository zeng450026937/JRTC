#ifndef JXMPP_JINGLEFILETRANSFERFILEINFOSERIALIZER_H
#define JXMPP_JINGLEFILETRANSFERFILEINFOSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleFileTransferFileInfo.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API JingleFileTransferFileInfoSerializer : public GenericPayloadSerializer<JingleFileTransferFileInfo> {
        public:
            JingleFileTransferFileInfoSerializer();

            virtual std::string serializePayload(std::shared_ptr<JingleFileTransferFileInfo>)  const;
    };
}

#endif // JXMPP_JINGLEFILETRANSFERFILEINFOSERIALIZER_H
