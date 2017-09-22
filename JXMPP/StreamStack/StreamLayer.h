#ifndef JXMPP_STREAMLAYER_H
#define JXMPP_STREAMLAYER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/StreamStack/HighLayer.h>
#include <JXMPP/StreamStack/LowLayer.h>

namespace JXMPP {
    class JXMPP_API StreamLayer : public LowLayer, public HighLayer {
        public:
            StreamLayer() {}
    };
}

#endif // JXMPP_STREAMLAYER_H
