#include <JXMPP/Disco/ClientDiscoManager.h>

#include <JXMPP/Disco/CapsInfoGenerator.h>
#include <JXMPP/Disco/DiscoInfoResponder.h>
#include <JXMPP/Presence/PayloadAddingPresenceSender.h>

namespace JXMPP {

ClientDiscoManager::ClientDiscoManager(IQRouter* iqRouter, PresenceSender* presenceSender, CryptoProvider* crypto) : crypto(crypto) {
    discoInfoResponder = new DiscoInfoResponder(iqRouter);
    discoInfoResponder->start();
    this->presenceSender = new PayloadAddingPresenceSender(presenceSender);
}

ClientDiscoManager::~ClientDiscoManager() {
    delete presenceSender;
    discoInfoResponder->stop();
    delete discoInfoResponder;
}

void ClientDiscoManager::setCapsNode(const std::string& node) {
    capsNode = node;
}

void ClientDiscoManager::setDiscoInfo(const DiscoInfo& discoInfo) {
    capsInfo = CapsInfo::ref(new CapsInfo(CapsInfoGenerator(capsNode, crypto).generateCapsInfo(discoInfo)));
    discoInfoResponder->clearDiscoInfo();
    discoInfoResponder->setDiscoInfo(discoInfo);
    discoInfoResponder->setDiscoInfo(capsInfo->getNode() + "#" + capsInfo->getVersion(), discoInfo);
    presenceSender->setPayload(capsInfo);
}

void ClientDiscoManager::handleConnected() {
    presenceSender->reset();
}

}
