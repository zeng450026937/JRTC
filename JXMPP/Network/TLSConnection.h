#ifndef JXMPP_TLSCONNECTION_H
#define JXMPP_TLSCONNECTION_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/TLS/TLSOptions.h>

namespace JXMPP {
    class HostAddressPort;
    class TLSContextFactory;
    class TLSContext;

    class JXMPP_API TLSConnection : public Connection {
        public:

            TLSConnection(Connection::ref connection, TLSContextFactory* tlsFactory, const TLSOptions&);
            virtual ~TLSConnection();

            virtual void listen() {assert(false);}
            virtual void connect(const HostAddressPort& address);
            virtual void disconnect();
            virtual void write(const SafeByteArray& data);

            virtual HostAddressPort getLocalAddress() const;
            virtual HostAddressPort getRemoteAddress() const;

            TLSContext* getTLSContext() const;

        private:
            void handleRawConnectFinished(bool error);
            void handleRawDisconnected(const boost::optional<Error>& error);
            void handleRawDataRead(std::shared_ptr<SafeByteArray> data);
            void handleRawDataWritten();
            void handleTLSConnectFinished(bool error);
            void handleTLSDataForNetwork(const SafeByteArray& data);
            void handleTLSDataForApplication(const SafeByteArray& data);

        private:
            TLSContext* context;
            Connection::ref connection;
    };
}

#endif // JXMPP_TLSCONNECTION_H
