#ifndef JXMPP_JINGLEFILETRANSFERDESCRIPTIONSERIALIZER_H
#define JXMPP_JINGLEFILETRANSFERDESCRIPTIONSERIALIZER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */





#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleFileTransferDescription.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API JingleFileTransferDescriptionSerializer : public GenericPayloadSerializer<JingleFileTransferDescription> {
        public:
            JingleFileTransferDescriptionSerializer();

            virtual std::string serializePayload(std::shared_ptr<JingleFileTransferDescription>)  const;
    };
}

#endif // JXMPP_JINGLEFILETRANSFERDESCRIPTIONSERIALIZER_H
