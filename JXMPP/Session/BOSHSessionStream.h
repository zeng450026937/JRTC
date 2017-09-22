#ifndef JXMPP_BOSHSESSIONSTREAM_H
#define JXMPP_BOSHSESSIONSTREAM_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Base/SafeString.h>
#include <JXMPP/Elements/StreamType.h>
#include <JXMPP/EventLoop/EventOwner.h>
#include <JXMPP/Network/BOSHConnectionPool.h>
#include <JXMPP/Session/SessionStream.h>
#include <JXMPP/TLS/TLSOptions.h>

namespace JXMPP {
    class EventLoop;
    class HTTPTrafficFilter;
    class PayloadParserFactoryCollection;
    class PayloadSerializerCollection;
    class TLSContextFactory;
    class TimerFactory;
    class XMLParserFactory;
    class XMPPLayer;

    class JXMPP_API BOSHSessionStream : public SessionStream, public EventOwner, public std::enable_shared_from_this<BOSHSessionStream> {
        public:
            BOSHSessionStream(
                    const URL& boshURL,
                    PayloadParserFactoryCollection* payloadParserFactories,
                    PayloadSerializerCollection* payloadSerializers,
                    ConnectionFactory* connectionFactory,
                    TLSContextFactory* tlsContextFactory,
                    TimerFactory* whitespacePingLayerFactory,
                    XMLParserFactory* xmlParserFactory,
                    EventLoop* eventLoop,
                    DomainNameResolver* resolver,
                    const std::string& to,
                    const URL& boshHTTPConnectProxyURL,
                    const SafeString& boshHTTPConnectProxyAuthID,
                    const SafeString& boshHTTPConnectProxyAuthPassword,
                    const TLSOptions& tlsOptions,
                    std::shared_ptr<HTTPTrafficFilter> trafficFilter
            );
            virtual ~BOSHSessionStream();

            void open();
            virtual void close();
            virtual bool isOpen();

            virtual void writeHeader(const ProtocolHeader& header);
            virtual void writeElement(std::shared_ptr<ToplevelElement>);
            virtual void writeFooter();
            virtual void writeData(const std::string& data);

            virtual bool supportsZLibCompression();
            virtual void addZLibCompression();

            virtual bool supportsTLSEncryption();
            virtual void addTLSEncryption();
            virtual bool isTLSEncrypted();
            virtual Certificate::ref getPeerCertificate() const;
            virtual std::vector<Certificate::ref> getPeerCertificateChain() const;
            virtual std::shared_ptr<CertificateVerificationError> getPeerCertificateVerificationError() const;
            virtual ByteArray getTLSFinishMessage() const;

            virtual void setWhitespacePingEnabled(bool);

            virtual void resetXMPPParser();

        private:
            void handleXMPPError();
            void handleStreamStartReceived(const ProtocolHeader&);
            void handleElementReceived(std::shared_ptr<ToplevelElement>);
            void handlePoolXMPPDataRead(const SafeByteArray& data);
            void handleXMPPLayerDataWritten(const SafeByteArray& data);
            void handlePoolSessionStarted();
            void handlePoolBOSHDataRead(const SafeByteArray& data);
            void handlePoolBOSHDataWritten(const SafeByteArray& data);
            void handlePoolSessionTerminated(BOSHError::ref condition);
            void handlePoolTLSEstablished();

        private:
            void fakeStreamHeaderReceipt();
            void fakeStreamFooterReceipt(BOSHError::ref error);

        private:
            BOSHConnectionPool* connectionPool;
            bool available;
            XMPPLayer* xmppLayer;
            ProtocolHeader streamHeader;
            EventLoop* eventLoop;
            bool firstHeader;
    };

}

#endif // JXMPP_BOSHSESSIONSTREAM_H
