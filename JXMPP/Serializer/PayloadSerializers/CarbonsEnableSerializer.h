#ifndef JXMPP_CARBONSENABLESERIALIZER_H
#define JXMPP_CARBONSENABLESERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CarbonsEnable.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API CarbonsEnableSerializer : public GenericPayloadSerializer<CarbonsEnable> {
        public:
            CarbonsEnableSerializer();
            virtual ~CarbonsEnableSerializer();

            virtual std::string serializePayload(std::shared_ptr<CarbonsEnable>)    const;
    };
}

#endif // JXMPP_CARBONSENABLESERIALIZER_H
