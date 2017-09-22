#ifndef JXMPP_STREAMSTACK_H
#define JXMPP_STREAMSTACK_H

#include <memory>
#include <vector>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Stanza.h>

namespace JXMPP {
    class XMPPLayer;
    class LowLayer;
    class StreamLayer;

    class JXMPP_API StreamStack {
        public:
            StreamStack(XMPPLayer* xmppLayer, LowLayer* physicalLayer);
            ~StreamStack();

            void addLayer(StreamLayer*);

            XMPPLayer* getXMPPLayer() const {
                return xmppLayer_;
            }

            template<typename T> T* getLayer() {
                for (auto& i : layers_) {
                    T* layer = dynamic_cast<T*>(i);
                    if (layer) {
                        return layer;
                    }
                }
                return nullptr;
            }

        private:
            XMPPLayer* xmppLayer_;
            LowLayer* physicalLayer_;
            std::vector<StreamLayer*> layers_;
    };
}

#endif // JXMPP_STREAMSTACK_H
