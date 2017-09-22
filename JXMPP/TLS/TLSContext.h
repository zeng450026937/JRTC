#ifndef JXMPP_TLSCONTEXT_H
#define JXMPP_TLSCONTEXT_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/TLS/Certificate.h>
#include <JXMPP/TLS/CertificateVerificationError.h>
#include <JXMPP/TLS/CertificateWithKey.h>
#include <JXMPP/TLS/TLSError.h>

namespace JXMPP {

    class JXMPP_API TLSContext {
        public:
            virtual ~TLSContext();

            virtual void connect() = 0;

            virtual bool setClientCertificate(CertificateWithKey::ref cert) = 0;

            virtual void handleDataFromNetwork(const SafeByteArray&) = 0;
            virtual void handleDataFromApplication(const SafeByteArray&) = 0;

            Certificate::ref getPeerCertificate() const;
            virtual std::vector<Certificate::ref> getPeerCertificateChain() const = 0;
            virtual CertificateVerificationError::ref getPeerCertificateVerificationError() const = 0;

            virtual ByteArray getFinishMessage() const = 0;

        public:
            boost::signals2::signal<void (const SafeByteArray&)> onDataForNetwork;
            boost::signals2::signal<void (const SafeByteArray&)> onDataForApplication;
            boost::signals2::signal<void (std::shared_ptr<TLSError>)> onError;
            boost::signals2::signal<void ()> onConnected;
    };
}

#endif // JXMPP_TLSCONTEXT_H
