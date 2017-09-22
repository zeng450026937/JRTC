#ifndef JXMPP_JINGLEFILETRANSFERHASHSERIALIZER_H
#define JXMPP_JINGLEFILETRANSFERHASHSERIALIZER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */





#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleFileTransferHash.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API JingleFileTransferHashSerializer : public GenericPayloadSerializer<JingleFileTransferHash> {
        public:
            JingleFileTransferHashSerializer();

            virtual std::string serializePayload(std::shared_ptr<JingleFileTransferHash>)  const;
    };
}

#endif // JXMPP_JINGLEFILETRANSFERHASHSERIALIZER_H
