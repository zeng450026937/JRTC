#ifndef JXMPP_BASICSESSIONSTREAM_H
#define JXMPP_BASICSESSIONSTREAM_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Elements/StreamType.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/Session/SessionStream.h>
#include <JXMPP/TLS/TLSError.h>
#include <JXMPP/TLS/TLSOptions.h>

namespace JXMPP {
    class TLSContextFactory;
    class TLSLayer;
    class TimerFactory;
    class WhitespacePingLayer;
    class PayloadParserFactoryCollection;
    class PayloadSerializerCollection;
    class StreamStack;
    class XMPPLayer;
    class ConnectionLayer;
    class CompressionLayer;
    class XMLParserFactory;

    class JXMPP_API BasicSessionStream : public SessionStream {
        public:
            BasicSessionStream(
                StreamType streamType,
                std::shared_ptr<Connection> connection,
                PayloadParserFactoryCollection* payloadParserFactories,
                PayloadSerializerCollection* payloadSerializers,
                TLSContextFactory* tlsContextFactory,
                TimerFactory* whitespacePingLayerFactory,
                XMLParserFactory* xmlParserFactory,
                const TLSOptions& tlsOptions
            );
            virtual ~BasicSessionStream();

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
            void handleConnectionFinished(const boost::optional<Connection::Error>& error);
            void handleXMPPError();
            void handleTLSConnected();
            void handleTLSError(std::shared_ptr<TLSError>);
            void handleStreamStartReceived(const ProtocolHeader&);
            void handleStreamEndReceived();
            void handleElementReceived(std::shared_ptr<ToplevelElement>);
            void handleDataRead(const SafeByteArray& data);
            void handleDataWritten(const SafeByteArray& data);

        private:
            bool available;
            std::shared_ptr<Connection> connection;
            TLSContextFactory* tlsContextFactory;
            TimerFactory* timerFactory;
            XMPPLayer* xmppLayer;
            ConnectionLayer* connectionLayer;
            CompressionLayer* compressionLayer;
            TLSLayer* tlsLayer;
            WhitespacePingLayer* whitespacePingLayer;
            StreamStack* streamStack;
            TLSOptions tlsOptions_;
    };

}

#endif // JXMPP_BASICSESSIONSTREAM_H
