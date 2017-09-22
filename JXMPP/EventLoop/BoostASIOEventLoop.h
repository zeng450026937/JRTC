#ifndef JXMPP_BOOSTASIOEVENTLOOP_H
#define JXMPP_BOOSTASIOEVENTLOOP_H

#include <memory>
#include <mutex>

#include <boost/asio/io_service.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/EventLoop/Event.h>
#include <JXMPP/EventLoop/EventLoop.h>

namespace JXMPP {
    class JXMPP_API BoostASIOEventLoop : public EventLoop {
        public:
            BoostASIOEventLoop(std::shared_ptr<boost::asio::io_service> ioService);
            virtual ~BoostASIOEventLoop();

        protected:
            void handleASIOEvent();

            virtual void eventPosted();

        private:
            std::shared_ptr<boost::asio::io_service> ioService_;

            bool isEventInASIOEventLoop_ = false;
            std::recursive_mutex isEventInASIOEventLoopMutex_;
    };
}

#endif // JXMPP_BOOSTASIOEVENTLOOP_H
