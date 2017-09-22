#include <JXMPP/StreamStack/LowLayer.h>

#include <cassert>

#include <JXMPP/StreamStack/HighLayer.h>

namespace JXMPP {

LowLayer::LowLayer() : parentLayer(nullptr) {
}

LowLayer::~LowLayer() {
}

void LowLayer::writeDataToParentLayer(const SafeByteArray& data) {
    assert(parentLayer);
    parentLayer->handleDataRead(data);
}

}
