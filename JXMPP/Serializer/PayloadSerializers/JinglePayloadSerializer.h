#ifndef JXMPP_JINGLEPAYLOADSERIALIZER_H
#define JXMPP_JINGLEPAYLOADSERIALIZER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */





#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JinglePayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API JinglePayloadSerializer : public GenericPayloadSerializer<JinglePayload> {
        public:
            JinglePayloadSerializer(PayloadSerializerCollection*);

            virtual std::string serializePayload(std::shared_ptr<JinglePayload>)  const;

        private:
            std::string actionToString(JinglePayload::Action action) const;
            std::string reasonTypeToString(JinglePayload::Reason::Type type) const;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_JINGLEPAYLOADSERIALIZER_H
