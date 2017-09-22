#ifndef JXMPP_MIXDESTROYSERIALIZER_H
#define JXMPP_MIXDESTROYSERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXDestroy.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {

    class JXMPP_API MIXDestroySerializer : public GenericPayloadSerializer<MIXDestroy> {
        public:
            MIXDestroySerializer();
            virtual ~MIXDestroySerializer() override;

            virtual std::string serializePayload(std::shared_ptr<MIXDestroy>) const override;
    };
}

#endif // JXMPP_MIXDESTROYSERIALIZER_H
