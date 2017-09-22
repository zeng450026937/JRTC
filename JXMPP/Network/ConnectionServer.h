#ifndef JXMPP_CONNECTIONSERVER_H
#define JXMPP_CONNECTIONSERVER_H

#include <memory>

#include <boost/optional/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/Network/HostAddressPort.h>

namespace JXMPP {
    class JXMPP_API ConnectionServer {
        public:
            enum Error {
                Conflict,
                UnknownError
            };

            virtual ~ConnectionServer();

            virtual HostAddressPort getAddressPort() const = 0;

            virtual boost::optional<Error> tryStart() = 0; // FIXME: This should become the new start

            virtual void start() = 0;

            virtual void stop() = 0;

            boost::signals2::signal<void (std::shared_ptr<Connection>)> onNewConnection;
    };
}

#endif // JXMPP_CONNECTIONSERVER_H
