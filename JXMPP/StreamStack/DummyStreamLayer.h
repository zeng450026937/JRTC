#ifndef JXMPP_DUMMYSTREAMLAYER_H
#define JXMPP_DUMMYSTREAMLAYER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/StreamStack/HighLayer.h>
#include <JXMPP/StreamStack/LowLayer.h>

namespace JXMPP {
    /**
     *  The \ref DummyStreamLayer can be used to use a \ref LowLayer on its own, without a functioning parent layer.
     *  The \ref DummyStreamLayer will serve as the parent layer to the \ref LowLayer and is called when the \ref LowLayer
     *  wants to write data to its parent layer.
     */
    class JXMPP_API DummyStreamLayer : public HighLayer {
        public:
            DummyStreamLayer(LowLayer* lowLayer) {
                setChildLayer(lowLayer);
                lowLayer->setParentLayer(this);
            }

            virtual void handleDataRead(const SafeByteArray& /* data */) {

            }
    };
}

#endif // JXMPP_DUMMYSTREAMLAYER_H
