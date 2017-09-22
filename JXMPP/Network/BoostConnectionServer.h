#ifndef JXMPP_BOOSTCONNECTIONSERVER_H
#define JXMPP_BOOSTCONNECTIONSERVER_H

#include <memory>

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/optional/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/EventLoop/EventOwner.h>
#include <JXMPP/Network/BoostConnection.h>
#include <JXMPP/Network/ConnectionServer.h>

namespace JXMPP {
    class JXMPP_API BoostConnectionServer : public ConnectionServer, public EventOwner, public std::enable_shared_from_this<BoostConnectionServer> {
        public:
            typedef std::shared_ptr<BoostConnectionServer> ref;

            static ref create(int port, std::shared_ptr<boost::asio::io_service> ioService, EventLoop* eventLoop) {
                return ref(new BoostConnectionServer(port, ioService, eventLoop));
            }

            static ref create(const HostAddress &address, int port, std::shared_ptr<boost::asio::io_service> ioService, EventLoop* eventLoop) {
                return ref(new BoostConnectionServer(address, port, ioService, eventLoop));
            }

            virtual boost::optional<Error> tryStart(); // FIXME: This should become the new start
            virtual void start();
            virtual void stop();

            virtual HostAddressPort getAddressPort() const;

            boost::signals2::signal<void (boost::optional<Error>)> onStopped;

        private:
            BoostConnectionServer(int port, std::shared_ptr<boost::asio::io_service> ioService, EventLoop* eventLoop);
            BoostConnectionServer(const HostAddress &address, int port, std::shared_ptr<boost::asio::io_service> ioService, EventLoop* eventLoop);

            void stop(boost::optional<Error> e);
            void acceptNextConnection();
            void handleAccept(std::shared_ptr<BoostConnection> newConnection, const boost::system::error_code& error);

        private:
            HostAddress address_;
            int port_;
            std::shared_ptr<boost::asio::io_service> ioService_;
            EventLoop* eventLoop;
            boost::asio::ip::tcp::acceptor* acceptor_;
    };
}

#endif // JXMPP_BOOSTCONNECTIONSERVER_H
