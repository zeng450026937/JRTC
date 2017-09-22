#ifndef JXMPP_LOCALJINGLETRANSPORTCANDIDATEGENERATOR_H
#define JXMPP_LOCALJINGLETRANSPORTCANDIDATEGENERATOR_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/FileTransfer/LocalJingleTransportCandidateGenerator.h>

#include <boost/signals2.hpp>

#include <JXMPP/Base/IDGenerator.h>
#include <JXMPP/Elements/JingleS5BTransportPayload.h>
#include <JXMPP/FileTransfer/FileTransferOptions.h>
#include <JXMPP/FileTransfer/SOCKS5BytestreamProxyFinder.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class SOCKS5BytestreamServerManager;
    class SOCKS5BytestreamProxiesManager;
    class SOCKS5BytestreamServerInitializeRequest;
    class SOCKS5BytestreamServerResourceUser;
    class SOCKS5BytestreamServerPortForwardingUser;
    class JingleS5BTransportPayload;

    class LocalJingleTransportCandidateGenerator {
        public:
            LocalJingleTransportCandidateGenerator(
                    SOCKS5BytestreamServerManager* s5bServerManager,
                    SOCKS5BytestreamProxiesManager* s5bProxy,
                    const JID& ownJID,
                    IDGenerator* idGenerator,
                    const FileTransferOptions& options);
            virtual ~LocalJingleTransportCandidateGenerator();

            virtual void start();
            virtual void stop();

            boost::signals2::signal<void (const std::vector<JingleS5BTransportPayload::Candidate>&)> onLocalTransportCandidatesGenerated;

        private:
            void handleS5BServerInitialized(bool success);
            void handlePortForwardingSetup(bool success);
            void handleDiscoveredProxiesChanged();

            void checkS5BCandidatesReady();
            void emitOnLocalTransportCandidatesGenerated();

        private:
            SOCKS5BytestreamServerManager* s5bServerManager;
            SOCKS5BytestreamProxiesManager* s5bProxy;
            JID ownJID;
            IDGenerator* idGenerator;
            std::shared_ptr<SOCKS5BytestreamServerInitializeRequest> s5bServerInitializeRequest;
            std::shared_ptr<SOCKS5BytestreamServerResourceUser> s5bServerResourceUser_;
            std::shared_ptr<SOCKS5BytestreamServerPortForwardingUser> s5bServerPortForwardingUser_;
            bool triedServerInit_;
            bool triedForwarding_;
            bool triedProxyDiscovery_;
            FileTransferOptions options_;
    };
}

#endif // JXMPP_LOCALJINGLETRANSPORTCANDIDATEGENERATOR_H
