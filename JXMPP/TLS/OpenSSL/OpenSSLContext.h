#ifndef JXMPP_OPENSSLCONTEXT_H
#define JXMPP_OPENSSLCONTEXT_H

#include <boost/noncopyable.hpp>
#include <boost/signals2.hpp>

#include <openssl/ssl.h>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/TLS/CertificateWithKey.h>
#include <JXMPP/TLS/TLSContext.h>

namespace JXMPP {

    class OpenSSLContext : public TLSContext, boost::noncopyable {
        public:
            OpenSSLContext();
            virtual ~OpenSSLContext();

            void connect();
            bool setClientCertificate(CertificateWithKey::ref cert);

            void handleDataFromNetwork(const SafeByteArray&);
            void handleDataFromApplication(const SafeByteArray&);

            std::vector<Certificate::ref> getPeerCertificateChain() const;
            std::shared_ptr<CertificateVerificationError> getPeerCertificateVerificationError() const;

            virtual ByteArray getFinishMessage() const;

        private:
            static void ensureLibraryInitialized();

            static CertificateVerificationError::Type getVerificationErrorTypeForResult(int);

            void doConnect();
            void sendPendingDataToNetwork();
            void sendPendingDataToApplication();

        private:
            enum State { Start, Connecting, Connected, Error };

            State state_;
            SSL_CTX* context_;
            SSL* handle_;
            BIO* readBIO_;
            BIO* writeBIO_;
    };
}

#endif // JXMPP_OPENSSLCONTEXT_H
