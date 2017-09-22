#include <JXMPP/MUC/MUCRegistry.h>

#include <JXMPP/Base/Algorithm.h>

namespace JXMPP {

MUCRegistry::~MUCRegistry() {
}

bool MUCRegistry::isMUC(const JID& j) const {
    return std::find(mucs.begin(), mucs.end(), j) != mucs.end();
}

void MUCRegistry::addMUC(const JID& j) {
    mucs.push_back(j);
}

void MUCRegistry::removeMUC(const JID& j) {
    erase(mucs, j);
}


}
