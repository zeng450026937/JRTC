#ifndef JXMPP_DEFAULTFILETRANSFERTRANSPORTERFACTORY_H
#define JXMPP_DEFAULTFILETRANSFERTRANSPORTERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/FileTransferTransporterFactory.h>

namespace JXMPP {
    class SOCKS5BytestreamRegistry;
    class SOCKS5BytestreamServerManager;
    class SOCKS5BytestreamProxiesManager;
    class IDGenerator;
    class ConnectionFactory;
    class TimerFactory;
    class CryptoProvider;
    class IQRouter;

    class JXMPP_API DefaultFileTransferTransporterFactory : public FileTransferTransporterFactory {
        public:
            DefaultFileTransferTransporterFactory(
                SOCKS5BytestreamRegistry*,
                SOCKS5BytestreamServerManager* s5bServerManager,
                SOCKS5BytestreamProxiesManager* s5bProxy,
                IDGenerator* idGenerator,
                ConnectionFactory*,
                TimerFactory*,
                CryptoProvider*,
                IQRouter*);
            virtual ~DefaultFileTransferTransporterFactory() override;

            virtual FileTransferTransporter* createInitiatorTransporter(
                    const JID& initiator, const JID& responder, const FileTransferOptions&) override;
            virtual FileTransferTransporter* createResponderTransporter(
                    const JID& initiator, const JID& responder, const std::string& s5bSessionID, const FileTransferOptions&) override;

        private:
            SOCKS5BytestreamRegistry* s5bRegistry;
            SOCKS5BytestreamServerManager* s5bServerManager;
            SOCKS5BytestreamProxiesManager* s5bProxiesManager;
            IDGenerator* idGenerator;
            ConnectionFactory* connectionFactory;
            TimerFactory* timerFactory;
            CryptoProvider* cryptoProvider;
            IQRouter* iqRouter;
    };
}

#endif // JXMPP_DEFAULTFILETRANSFERTRANSPORTERFACTORY_H
