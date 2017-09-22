#include <JXMPP/Client/Client.h>

#include <JXMPP/Avatars/AvatarManagerImpl.h>
#include <JXMPP/Base/SafeString.h>
#include <JXMPP/Client/ClientBlockListManager.h>
#include <JXMPP/Client/ClientSession.h>
#include <JXMPP/Client/MemoryStorages.h>
#include <JXMPP/Client/NickManagerImpl.h>
#include <JXMPP/Client/NickResolver.h>
#include <JXMPP/Disco/CapsManager.h>
#include <JXMPP/Disco/ClientDiscoManager.h>
#include <JXMPP/Disco/EntityCapsManager.h>
#include <JXMPP/FileTransfer/FileTransferManagerImpl.h>
#include <JXMPP/Jingle/JingleSessionManager.h>
#include <JXMPP/MUC/MUCManager.h>
#include <JXMPP/MUC/MUCRegistry.h>
#include <JXMPP/Network/NetworkFactories.h>
#include <JXMPP/Presence/DirectedPresenceSender.h>
#include <JXMPP/Presence/PresenceOracle.h>
#include <JXMPP/Presence/StanzaChannelPresenceSender.h>
#include <JXMPP/Presence/SubscriptionManager.h>
#include <JXMPP/PubSub/PubSubManagerImpl.h>
#include <JXMPP/Queries/Responders/SoftwareVersionResponder.h>
#include <JXMPP/Roster/XMPPRosterController.h>
#include <JXMPP/Roster/XMPPRosterImpl.h>
#include <JXMPP/TLS/BlindCertificateTrustChecker.h>
#include <JXMPP/VCards/VCardManager.h>
#include <JXMPP/VCards/VCardManager.h>
#include <JXMPP/Whiteboard/WhiteboardSessionManager.h>

#ifndef JXMPP_EXPERIMENTAL_FT
#include <JXMPP/FileTransfer/UnitTest/DummyFileTransferManager.h>
#endif

namespace JXMPP {

Client::Client(const JID& jid, const SafeString& password, NetworkFactories* networkFactories, Storages* storages) : CoreClient(jid, password, networkFactories), storages(storages) {
    memoryStorages = new MemoryStorages(networkFactories->getCryptoProvider());

    softwareVersionResponder = new SoftwareVersionResponder(getIQRouter());
    softwareVersionResponder->start();

    roster = new XMPPRosterImpl();
    rosterController = new XMPPRosterController(getIQRouter(), roster, getStorages()->getRosterStorage());

    subscriptionManager = new SubscriptionManager(getStanzaChannel());

    presenceOracle = new PresenceOracle(getStanzaChannel(), roster);
    presenceOracle->onPresenceChange.connect(boost::ref(onPresenceChange));

    stanzaChannelPresenceSender = new StanzaChannelPresenceSender(getStanzaChannel());
    directedPresenceSender = new DirectedPresenceSender(stanzaChannelPresenceSender);
    discoManager = new ClientDiscoManager(getIQRouter(), directedPresenceSender, networkFactories->getCryptoProvider());

    mucRegistry = new MUCRegistry();
    mucManager = new MUCManager(getStanzaChannel(), getIQRouter(), directedPresenceSender, mucRegistry);

    vcardManager = new VCardManager(jid, getIQRouter(), getStorages()->getVCardStorage());
    avatarManager = new AvatarManagerImpl(vcardManager, getStanzaChannel(), getStorages()->getAvatarStorage(), networkFactories->getCryptoProvider(), mucRegistry);
    capsManager = new CapsManager(getStorages()->getCapsStorage(), getStanzaChannel(), getIQRouter(), networkFactories->getCryptoProvider());
    entityCapsManager = new EntityCapsManager(capsManager, getStanzaChannel());

    nickManager = new NickManagerImpl(jid.toBare(), vcardManager);
    nickResolver = new NickResolver(jid.toBare(), roster, vcardManager, mucRegistry);

    blindCertificateTrustChecker = new BlindCertificateTrustChecker();

    jingleSessionManager = new JingleSessionManager(getIQRouter());
    blockListManager = new ClientBlockListManager(getIQRouter());

    whiteboardSessionManager = nullptr;
#ifdef JXMPP_EXPERIMENTAL_WB
    whiteboardSessionManager = new WhiteboardSessionManager(getIQRouter(), getStanzaChannel(), presenceOracle, getEntityCapsProvider());
#endif

    pubsubManager = new PubSubManagerImpl(getStanzaChannel(), getIQRouter());

#ifdef JXMPP_EXPERIMENTAL_FT
    fileTransferManager = new FileTransferManagerImpl(
            getJID(),
            jingleSessionManager,
            getIQRouter(),
            getEntityCapsProvider(),
            presenceOracle,
            getNetworkFactories()->getConnectionFactory(),
            getNetworkFactories()->getConnectionServerFactory(),
            getNetworkFactories()->getTimerFactory(),
            getNetworkFactories()->getDomainNameResolver(),
            getNetworkFactories()->getNetworkEnvironment(),
            getNetworkFactories()->getNATTraverser(),
            getNetworkFactories()->getCryptoProvider());
#else
    fileTransferManager = new DummyFileTransferManager();
#endif
}

Client::~Client() {
    delete pubsubManager;
    delete whiteboardSessionManager;

    delete fileTransferManager;
    delete blockListManager;
    delete jingleSessionManager;

    delete blindCertificateTrustChecker;

    delete nickResolver;
    delete nickManager;

    delete entityCapsManager;
    delete capsManager;
    delete avatarManager;
    delete vcardManager;

    delete mucManager;
    delete mucRegistry;

    delete discoManager;
    delete directedPresenceSender;
    delete stanzaChannelPresenceSender;

    delete presenceOracle;
    delete subscriptionManager;
    delete rosterController;
    delete roster;

    softwareVersionResponder->stop();
    delete softwareVersionResponder;

    delete memoryStorages;
}

XMPPRoster* Client::getRoster() const {
    return roster;
}

void Client::setSoftwareVersion(const std::string& name, const std::string& version, const std::string& os) {
    softwareVersionResponder->setVersion(name, version, os);
}

void Client::handleConnected() {
    discoManager->handleConnected();
}

void Client::requestRoster() {
    // FIXME: We should set this once when the session is finished, but there
    // is currently no callback for this
    if (getSession()) {
        rosterController->setUseVersioning(getSession()->getRosterVersioningSupported());
    }
    rosterController->requestRoster();
}

Presence::ref Client::getLastPresence(const JID& jid) const {
    return presenceOracle->getLastPresence(jid);
}

Presence::ref Client::getHighestPriorityPresence(const JID& bareJID) const {
    return presenceOracle->getHighestPriorityPresence(bareJID);
}

Storages* Client::getStorages() const {
    if (storages) {
        return storages;
    }
    return memoryStorages;
}

PresenceSender* Client::getPresenceSender() const {
    return discoManager->getPresenceSender();
}

EntityCapsProvider* Client::getEntityCapsProvider() const {
    return entityCapsManager;
}


void Client::setAlwaysTrustCertificates() {
    setCertificateTrustChecker(blindCertificateTrustChecker);
}

NickManager* Client::getNickManager() const {
    return nickManager;
}

FileTransferManager* Client::getFileTransferManager() const {
    return fileTransferManager;
}

WhiteboardSessionManager* Client::getWhiteboardSessionManager() const {
    return whiteboardSessionManager;
}

}
