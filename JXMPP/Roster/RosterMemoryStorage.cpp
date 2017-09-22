#include <JXMPP/Roster/RosterMemoryStorage.h>

#include <memory>

namespace JXMPP {

RosterMemoryStorage::RosterMemoryStorage() {
}

void RosterMemoryStorage::setRoster(std::shared_ptr<RosterPayload> r) {
    roster.reset();
    if (r) {
        roster = std::make_shared<RosterPayload>(*r);
    }
}

}
