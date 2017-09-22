#include <JXMPP/StreamStack/HighLayer.h>

#include <cassert>

#include <JXMPP/StreamStack/LowLayer.h>

namespace JXMPP {

HighLayer::HighLayer() : childLayer(nullptr) {
}

HighLayer::~HighLayer() {
}

void HighLayer::writeDataToChildLayer(const SafeByteArray& data) {
    //assert(childLayer);
    if (childLayer) {
        childLayer->writeData(data);
    }
}

}
