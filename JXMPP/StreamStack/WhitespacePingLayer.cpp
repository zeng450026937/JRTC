#include <JXMPP/StreamStack/WhitespacePingLayer.h>

#include <boost/bind.hpp>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Network/Timer.h>
#include <JXMPP/Network/TimerFactory.h>

namespace JXMPP {

static const int TIMEOUT_MILLISECONDS = 60000;

WhitespacePingLayer::WhitespacePingLayer(TimerFactory* timerFactory) : isActive(false) {
    timer = timerFactory->createTimer(TIMEOUT_MILLISECONDS);
    timer->onTick.connect(boost::bind(&WhitespacePingLayer::handleTimerTick, this));
}

WhitespacePingLayer::~WhitespacePingLayer() {
    JXMPP_LOG_ASSERT(!isActive, debug) << "WhitespacePingLayer still active at destruction." << std::endl;
    if (isActive) {
        timer->stop();
    }
    timer->onTick.disconnect(boost::bind(&WhitespacePingLayer::handleTimerTick, this));
}

void WhitespacePingLayer::writeData(const SafeByteArray& data) {
    writeDataToChildLayer(data);
}

void WhitespacePingLayer::handleDataRead(const SafeByteArray& data) {
    writeDataToParentLayer(data);
}

void WhitespacePingLayer::handleTimerTick() {
    timer->stop();
    writeDataToChildLayer(createSafeByteArray(" "));
    timer->start();
}

void WhitespacePingLayer::setActive() {
    isActive = true;
    timer->start();
}

void WhitespacePingLayer::setInactive() {
    timer->stop();
    isActive = false;
}

}
