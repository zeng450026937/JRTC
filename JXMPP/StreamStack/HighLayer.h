#ifndef JXMPP_HIGHLAYER_H
#define JXMPP_HIGHLAYER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class LowLayer;

    class JXMPP_API HighLayer {
            friend class StreamStack;

        public:
            HighLayer();
            virtual ~HighLayer();

            virtual void handleDataRead(const SafeByteArray& data) = 0;

        protected:
            LowLayer* getChildLayer() {
                return childLayer;
            }

            void setChildLayer(LowLayer* childLayer) {
                this->childLayer = childLayer;
            }

            void writeDataToChildLayer(const SafeByteArray& data);

        private:
            LowLayer* childLayer;
    };
}

#endif // JXMPP_HIGHLAYER_H
