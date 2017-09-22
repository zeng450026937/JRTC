#ifndef JXMPP_MIXUSERPREFERENCESERIALIZER_H
#define JXMPP_MIXUSERPREFERENCESERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXUserPreference.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {

    class JXMPP_API MIXUserPreferenceSerializer : public GenericPayloadSerializer<MIXUserPreference> {
        public:
            MIXUserPreferenceSerializer();
            virtual ~MIXUserPreferenceSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<MIXUserPreference>) const override;
    };
}

#endif // JXMPP_MIXUSERPREFERENCESERIALIZER_H
