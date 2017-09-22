#include <JXMPP/MUC/MUCManager.h>

#include <JXMPP/MUC/MUCImpl.h>

namespace JXMPP {

MUCManager::MUCManager(StanzaChannel* stanzaChannel, IQRouter* iqRouter, DirectedPresenceSender* presenceSender, MUCRegistry* mucRegistry) : stanzaChannel(stanzaChannel), iqRouter(iqRouter), presenceSender(presenceSender), mucRegistry(mucRegistry) {
}

MUC::ref MUCManager::createMUC(const JID& jid) {
    return std::make_shared<MUCImpl>(stanzaChannel, iqRouter, presenceSender, jid, mucRegistry);
}

}
