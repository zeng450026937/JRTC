#ifndef JXMPP_STREAMFEATURESSERIALIZER_H
#define JXMPP_STREAMFEATURESSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamFeatures.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>

namespace JXMPP {
    class JXMPP_API StreamFeaturesSerializer : public GenericElementSerializer<StreamFeatures> {
        public:
            StreamFeaturesSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element)  const;
    };
}

#endif // JXMPP_STREAMFEATURESSERIALIZER_H
