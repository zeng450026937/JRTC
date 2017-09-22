#include <JXMPP/StreamStack/StreamStack.h>

#include <boost/bind.hpp>

#include <JXMPP/StreamStack/LowLayer.h>
#include <JXMPP/StreamStack/StreamLayer.h>
#include <JXMPP/StreamStack/XMPPLayer.h>

namespace JXMPP {

StreamStack::StreamStack(XMPPLayer* xmppLayer, LowLayer* physicalLayer) : xmppLayer_(xmppLayer), physicalLayer_(physicalLayer) {
    physicalLayer_->setParentLayer(xmppLayer_);
    xmppLayer_->setChildLayer(physicalLayer_);
}

StreamStack::~StreamStack() {
}

void StreamStack::addLayer(StreamLayer* newLayer) {
    LowLayer* lowLayer = layers_.empty() ? physicalLayer_ : *layers_.rbegin();

    xmppLayer_->setChildLayer(newLayer);
    newLayer->setParentLayer(xmppLayer_);

    lowLayer->setParentLayer(newLayer);
    newLayer->setChildLayer(lowLayer);

    layers_.push_back(newLayer);
}

}
