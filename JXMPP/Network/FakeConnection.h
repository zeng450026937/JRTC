#ifndef JXMPP_FAKECONNECTION_H
#define JXMPP_FAKECONNECTION_H

#include <memory>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/EventLoop/EventOwner.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/Network/HostAddressPort.h>

namespace JXMPP {
    class JXMPP_API FakeConnection :
            public Connection,
            public EventOwner,
            public std::enable_shared_from_this<FakeConnection> {
        public:
            enum State {
                Initial,
                Connecting,
                Connected,
                Disconnected,
                DisconnectedWithError
            };

            FakeConnection(EventLoop* eventLoop);
            virtual ~FakeConnection();

            virtual void listen();
            virtual HostAddressPort getLocalAddress() const {
                return HostAddressPort();
            }
            virtual HostAddressPort getRemoteAddress() const {
                return HostAddressPort();
            }

            void setError(const Error& e);
            virtual void connect(const HostAddressPort& address);
            virtual void disconnect();

            virtual void write(const SafeByteArray& data) {
                dataWritten.push_back(data);
            }

            void setDelayConnect() {
                delayConnect = true;
            }

            EventLoop* eventLoop;
            boost::optional<HostAddressPort> connectedTo;
            std::vector<SafeByteArray> dataWritten;
            boost::optional<Error> error;
            State state;
            bool delayConnect;
    };
}

#endif // JXMPP_FAKECONNECTION_H
