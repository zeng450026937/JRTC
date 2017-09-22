#ifndef JXMPP_MIXUPDATESUBSCRIPTIONSERIALIZER_H
#define JXMPP_MIXUPDATESUBSCRIPTIONSERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXUpdateSubscription.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {

    class JXMPP_API MIXUpdateSubscriptionSerializer : public GenericPayloadSerializer<MIXUpdateSubscription> {
        public:
            MIXUpdateSubscriptionSerializer();
            virtual ~MIXUpdateSubscriptionSerializer();

            virtual std::string serializePayload(std::shared_ptr<MIXUpdateSubscription>) const override;
    };
}

#endif // JXMPP_MIXUPDATESUBSCRIPTIONSERIALIZER_H
