#ifndef JXMPP_TLSLAYER_H
#define JXMPP_TLSLAYER_H

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/StreamStack/StreamLayer.h>
#include <JXMPP/TLS/Certificate.h>
#include <JXMPP/TLS/CertificateVerificationError.h>
#include <JXMPP/TLS/CertificateWithKey.h>
#include <JXMPP/TLS/TLSError.h>
#include <JXMPP/TLS/TLSOptions.h>

namespace JXMPP {
    class TLSContext;
    class TLSContextFactory;

    class JXMPP_API TLSLayer : public StreamLayer {
        public:
            TLSLayer(TLSContextFactory*, const TLSOptions&);
            virtual ~TLSLayer();

            void connect();
            bool setClientCertificate(CertificateWithKey::ref cert);

            Certificate::ref getPeerCertificate() const;
            std::vector<Certificate::ref> getPeerCertificateChain() const;
            std::shared_ptr<CertificateVerificationError> getPeerCertificateVerificationError() const;

            void writeData(const SafeByteArray& data);
            void handleDataRead(const SafeByteArray& data);

            TLSContext* getContext() const {
                return context;
            }

        public:
            boost::signals2::signal<void (std::shared_ptr<TLSError>)> onError;
            boost::signals2::signal<void ()> onConnected;

        private:
            TLSContext* context;
    };
}

#endif // JXMPP_TLSLAYER_H
