#ifndef JXMPP_JINGLES5BTRANSPORTPAYLOADSERIALIZER_H
#define JXMPP_JINGLES5BTRANSPORTPAYLOADSERIALIZER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */





#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleS5BTransportPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API JingleS5BTransportPayloadSerializer : public GenericPayloadSerializer<JingleS5BTransportPayload> {
        public:
            JingleS5BTransportPayloadSerializer();

            virtual std::string serializePayload(std::shared_ptr<JingleS5BTransportPayload>)  const;

        private:
            std::string modeToString(JingleS5BTransportPayload::Mode) const;
            std::string typeToString(JingleS5BTransportPayload::Candidate::Type) const;
    };
}

#endif // JXMPP_JINGLES5BTRANSPORTPAYLOADSERIALIZER_H
