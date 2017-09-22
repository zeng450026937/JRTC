#ifndef JXMPP_DUMMYTIMERFACTORY_H
#define JXMPP_DUMMYTIMERFACTORY_H

#include <list>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/TimerFactory.h>

namespace JXMPP {
    class JXMPP_API DummyTimerFactory : public TimerFactory {
        public:
            class DummyTimer;

            DummyTimerFactory();

            virtual std::shared_ptr<Timer> createTimer(int milliseconds);
            void setTime(int time);

        private:
            friend class DummyTimer;
            int currentTime;
            std::list<std::shared_ptr<DummyTimer> > timers;
    };
}

#endif // JXMPP_DUMMYTIMERFACTORY_H
