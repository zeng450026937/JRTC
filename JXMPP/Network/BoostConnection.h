#ifndef JXMPP_BOOSTCONNECTION_H
#define JXMPP_BOOSTCONNECTION_H

#include <memory>
#include <mutex>

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/EventLoop/EventOwner.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/TLS/Certificate.h>
#include <JXMPP/TLS/CertificateVerificationError.h>
#include <JXMPP/TLS/CertificateWithKey.h>

namespace JXMPP {
    class EventLoop;

    class JXMPP_API BoostConnection : public Connection, public EventOwner, public std::enable_shared_from_this<BoostConnection> {
        public:
            typedef std::shared_ptr<BoostConnection> ref;

            virtual ~BoostConnection();

            static ref create(std::shared_ptr<boost::asio::io_service> ioService, EventLoop* eventLoop) {
                return ref(new BoostConnection(ioService, eventLoop));
            }

            virtual void listen();
            virtual void connect(const HostAddressPort& address);
            virtual void disconnect();
            virtual void write(const SafeByteArray& data);

            boost::asio::ip::tcp::socket& getSocket() {
                return socket_;
            }

            virtual HostAddressPort getLocalAddress() const;
            virtual HostAddressPort getRemoteAddress() const;

            bool setClientCertificate(CertificateWithKey::ref cert);

            Certificate::ref getPeerCertificate() const;
            std::vector<Certificate::ref> getPeerCertificateChain() const;
            std::shared_ptr<CertificateVerificationError> getPeerCertificateVerificationError() const;

        private:
            BoostConnection(std::shared_ptr<boost::asio::io_service> ioService, EventLoop* eventLoop);

            void handleConnectFinished(const boost::system::error_code& error);
            void handleSocketRead(const boost::system::error_code& error, size_t bytesTransferred);
            void handleDataWritten(const boost::system::error_code& error);
            void doRead();
            void doWrite(const SafeByteArray& data);
            void closeSocket();

        private:
            EventLoop* eventLoop;
            std::shared_ptr<boost::asio::io_service> ioService;
            boost::asio::ip::tcp::socket socket_;
            std::shared_ptr<SafeByteArray> readBuffer_;
            std::mutex writeMutex_;
            bool writing_;
            SafeByteArray writeQueue_;
            bool closeSocketAfterNextWrite_;
            std::mutex readCloseMutex_;
    };
}

#endif // JXMPP_BOOSTCONNECTION_H
