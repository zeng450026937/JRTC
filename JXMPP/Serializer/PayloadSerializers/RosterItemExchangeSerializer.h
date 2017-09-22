#ifndef JXMPP_ROSTERITEMEXCHANGESERIALIZER_H
#define JXMPP_ROSTERITEMEXCHANGESERIALIZER_H

/*
 * Copyright (c) 2011 Jan Kaluza
 * Licensed under the Simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RosterItemExchangePayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API RosterItemExchangeSerializer : public GenericPayloadSerializer<RosterItemExchangePayload> {
        public:
            RosterItemExchangeSerializer();

            virtual std::string serializePayload(std::shared_ptr<RosterItemExchangePayload>)  const;
    };
}

#endif // JXMPP_ROSTERITEMEXCHANGESERIALIZER_H
