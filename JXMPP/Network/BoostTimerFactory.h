#ifndef JXMPP_BOOSTTIMERFACTORY_H
#define JXMPP_BOOSTTIMERFACTORY_H

#include <boost/asio/io_service.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/BoostTimer.h>
#include <JXMPP/Network/TimerFactory.h>

namespace JXMPP {
    class EventLoop;

    class JXMPP_API BoostTimerFactory : public TimerFactory {
        public:
            BoostTimerFactory(std::shared_ptr<boost::asio::io_service>, EventLoop* eventLoop);

            virtual std::shared_ptr<Timer> createTimer(int milliseconds);

        private:
            std::shared_ptr<boost::asio::io_service> ioService;
            EventLoop* eventLoop;
    };
}

#endif // JXMPP_BOOSTTIMERFACTORY_H
