#ifndef JXMPP_MIXCREATESERIALIZER_H
#define JXMPP_MIXCREATESERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXCreate.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {

    class JXMPP_API MIXCreateSerializer : public GenericPayloadSerializer<MIXCreate> {
        public:
            MIXCreateSerializer();
            virtual ~MIXCreateSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<MIXCreate>) const override;
    };
}

#endif // JXMPP_MIXCREATESERIALIZER_H
