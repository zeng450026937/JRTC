#ifndef JXMPP_SOCKS5BYTESTREAMSERVER_H
#define JXMPP_SOCKS5BYTESTREAMSERVER_H

#include <map>
#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/ReadBytestream.h>
#include <JXMPP/FileTransfer/SOCKS5BytestreamRegistry.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Network/ConnectionServer.h>

namespace JXMPP {
    class SOCKS5BytestreamServerSession;

    class JXMPP_API SOCKS5BytestreamServer {
        public:
            SOCKS5BytestreamServer(
                    std::shared_ptr<ConnectionServer> connectionServer,
                    SOCKS5BytestreamRegistry* registry);

            HostAddressPort getAddressPort() const;

            void start();
            void stop();

            std::vector< std::shared_ptr<SOCKS5BytestreamServerSession> > getSessions(const std::string& id) const;

        private:
            void handleNewConnection(std::shared_ptr<Connection> connection);
            void handleSessionFinished(std::shared_ptr<SOCKS5BytestreamServerSession>);

        private:
            friend class SOCKS5BytestreamServerSession;

            std::shared_ptr<ConnectionServer> connectionServer;
            SOCKS5BytestreamRegistry* registry;
            std::vector<std::shared_ptr<SOCKS5BytestreamServerSession> > sessions;
    };
}

#endif // JXMPP_SOCKS5BYTESTREAMSERVER_H
