#ifndef JXMPP_LOWLAYER_H
#define JXMPP_LOWLAYER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class HighLayer;

    class JXMPP_API LowLayer {
            friend class StreamStack;
            friend class DummyStreamLayer;

        public:
            LowLayer();
            virtual ~LowLayer();

            virtual void writeData(const SafeByteArray& data) = 0;

        protected:
            HighLayer* getParentLayer() {
                return parentLayer;
            }

            void setParentLayer(HighLayer* parentLayer) {
                this->parentLayer = parentLayer;
            }

            void writeDataToParentLayer(const SafeByteArray& data);

        private:
            HighLayer* parentLayer;
    };
}

#endif // JXMPP_LOWLAYER_H
