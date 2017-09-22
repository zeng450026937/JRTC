#ifndef JXMPP_TIMERFACTORY_H
#define JXMPP_TIMERFACTORY_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/Timer.h>

namespace JXMPP {
    class JXMPP_API TimerFactory {
        public:
            virtual ~TimerFactory();

            virtual Timer::ref createTimer(int milliseconds) = 0;
    };
}

#endif // JXMPP_TIMERFACTORY_H
