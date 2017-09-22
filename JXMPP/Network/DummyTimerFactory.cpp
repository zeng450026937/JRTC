#include <JXMPP/Network/DummyTimerFactory.h>

#include <algorithm>

#include <JXMPP/Network/Timer.h>

namespace JXMPP {

class DummyTimerFactory::DummyTimer : public Timer {
    public:
        DummyTimer(int timeout, DummyTimerFactory* factory) : timeout(timeout), factory(factory), isRunning(false), startTime(~0) {
        }

        virtual void start() {
            isRunning = true;
            startTime = factory->currentTime;
        }

        virtual void stop() {
            isRunning = false;
        }

        int getAlarmTime() const {
            return startTime + timeout;
        }

        int timeout;
        DummyTimerFactory* factory;
        bool isRunning;
        int startTime;
};


DummyTimerFactory::DummyTimerFactory() : currentTime(0) {
}

std::shared_ptr<Timer> DummyTimerFactory::createTimer(int milliseconds) {
    std::shared_ptr<DummyTimer> timer(new DummyTimer(milliseconds, this));
    timers.push_back(timer);
    return timer;
}

void DummyTimerFactory::setTime(int time) {
    assert(time > currentTime);
    for (auto&& timer : timers) {
        if (timer->getAlarmTime() > currentTime && timer->getAlarmTime() <= time && timer->isRunning) {
            timer->onTick();
        }
    }
    currentTime = time;
}

}
