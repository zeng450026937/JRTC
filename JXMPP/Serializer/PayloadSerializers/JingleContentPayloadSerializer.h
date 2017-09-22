#ifndef JXMPP_JINGLECONTENTPAYLOADSERIALIZER_H
#define JXMPP_JINGLECONTENTPAYLOADSERIALIZER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */





#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleContentPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API JingleContentPayloadSerializer : public GenericPayloadSerializer<JingleContentPayload> {
        public:
            JingleContentPayloadSerializer();

            virtual std::string serializePayload(std::shared_ptr<JingleContentPayload>)  const;

        private:
            std::string creatorToString(JingleContentPayload::Creator creator) const;
    };
}

#endif // JXMPP_JINGLECONTENTPAYLOADSERIALIZER_H
