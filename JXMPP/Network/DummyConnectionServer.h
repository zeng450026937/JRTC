#ifndef JXMPP_DUMMYCONNECTIONSERVER_H
#define JXMPP_DUMMYCONNECTIONSERVER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/EventLoop/EventOwner.h>
#include <JXMPP/Network/ConnectionServer.h>
#include <JXMPP/Network/HostAddressPort.h>

namespace JXMPP {
    class JXMPP_API DummyConnectionServer : public ConnectionServer, public EventOwner, public std::enable_shared_from_this<DummyConnectionServer> {
        public:
            DummyConnectionServer(EventLoop* /*eventLoop*/, int port) : localAddressPort(HostAddress(), port) {}
            DummyConnectionServer(EventLoop* /*eventLoop*/, const JXMPP::HostAddress& hostAddress, int port) : localAddressPort(hostAddress, port) {}
            virtual ~DummyConnectionServer() {}

            virtual HostAddressPort getAddressPort() const {
                return localAddressPort;
            }

            virtual boost::optional<Error> tryStart() {
                return boost::optional<Error>();
            }

            virtual void start() {

            }

            virtual void stop() {

            }

        private:
            HostAddressPort localAddressPort;
    };
}

#endif // JXMPP_DUMMYCONNECTIONSERVER_H
