#ifndef JXMPP_STREAMINITIATIONFILEINFOSERIALIZER_H
#define JXMPP_STREAMINITIATIONFILEINFOSERIALIZER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */





#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamInitiationFileInfo.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API StreamInitiationFileInfoSerializer : public GenericPayloadSerializer<StreamInitiationFileInfo> {
        public:
            StreamInitiationFileInfoSerializer();

            virtual std::string serializePayload(std::shared_ptr<StreamInitiationFileInfo>)  const;
    };
}

#endif // JXMPP_STREAMINITIATIONFILEINFOSERIALIZER_H
