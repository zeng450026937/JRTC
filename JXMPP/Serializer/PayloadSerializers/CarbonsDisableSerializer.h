#ifndef JXMPP_CARBONSDISABLESERIALIZER_H
#define JXMPP_CARBONSDISABLESERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CarbonsDisable.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API CarbonsDisableSerializer : public GenericPayloadSerializer<CarbonsDisable> {
        public:
            CarbonsDisableSerializer();
            virtual ~CarbonsDisableSerializer();

            virtual std::string serializePayload(std::shared_ptr<CarbonsDisable>)    const;
    };
}

#endif // JXMPP_CARBONSDISABLESERIALIZER_H
