#ifndef JXMPP_DUMMYCONNECTION_H
#define JXMPP_DUMMYCONNECTION_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/EventLoop/EventOwner.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/Network/HostAddressPort.h>

namespace JXMPP {
    class JXMPP_API DummyConnection : public Connection, public EventOwner,    public std::enable_shared_from_this<DummyConnection> {
        public:
            DummyConnection(EventLoop* eventLoop);

            void listen();
            void connect(const HostAddressPort&);

            void disconnect() {
                //assert(false);
            }

            void write(const SafeByteArray& data) {
                eventLoop->postEvent(boost::ref(onDataWritten), shared_from_this());
                onDataSent(data);
            }

            void receive(const SafeByteArray& data);

            HostAddressPort getLocalAddress() const {
                return localAddress;
            }

            HostAddressPort getRemoteAddress() const {
                return remoteAddress;
            }

            boost::signals2::signal<void (const SafeByteArray&)> onDataSent;

            EventLoop* eventLoop;
            HostAddressPort localAddress;
            HostAddressPort remoteAddress;
    };
}

#endif // JXMPP_DUMMYCONNECTION_H
