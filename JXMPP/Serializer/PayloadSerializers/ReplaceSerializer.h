#ifndef JXMPP_REPLACESERIALIZER_H
#define JXMPP_REPLACESERIALIZER_H

/*
 * Copyright (c) 2011 Vlad Voicu
 * Licensed under the Simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Replace.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {
    class JXMPP_API ReplaceSerializer : public GenericPayloadSerializer<Replace> {
        public:
            ReplaceSerializer() : GenericPayloadSerializer<Replace>() {}

            virtual std::string serializePayload(std::shared_ptr<Replace> replace) const {
                return "<replace id = '" + replace->getID() + "' xmlns='urn:xmpp:message-correct:0'/>";
            }
    };
}

#endif // JXMPP_REPLACESERIALIZER_H
