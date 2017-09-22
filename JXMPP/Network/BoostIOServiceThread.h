#ifndef JXMPP_BOOSTIOSERVICETHREAD_H
#define JXMPP_BOOSTIOSERVICETHREAD_H

#include <memory>
#include <thread>

#include <boost/asio/io_service.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API BoostIOServiceThread {
        public:
            /**
             * Construct the object.
             * @param ioService If this optional parameter is provided, the behaviour
             * of this class changes completely - it no longer spawns its own thread
             * and instead acts as a simple wrapper of the io_service. Use this if
             * you are re-using an io_service from elsewhere (particularly if you
           * are using the BoostASIOEventLoop).
             */
            BoostIOServiceThread(std::shared_ptr<boost::asio::io_service> ioService = std::shared_ptr<boost::asio::io_service>());
            ~BoostIOServiceThread();

            std::shared_ptr<boost::asio::io_service> getIOService() const {
                return ioService_;
            }

        private:
            void doRun();

        private:
            std::shared_ptr<boost::asio::io_service> ioService_;
            std::thread* thread_;
    };
}

#endif // JXMPP_BOOSTIOSERVICETHREAD_H
