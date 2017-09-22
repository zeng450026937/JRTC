#ifndef JXMPP_ROSTERMEMORYSTORAGE_H
#define JXMPP_ROSTERMEMORYSTORAGE_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Roster/RosterStorage.h>

namespace JXMPP {
    class JXMPP_API RosterMemoryStorage : public RosterStorage {
        public:
            RosterMemoryStorage();

            virtual std::shared_ptr<RosterPayload> getRoster() const {
                return roster;
            }

            virtual void setRoster(std::shared_ptr<RosterPayload>);

        private:
            std::shared_ptr<RosterPayload> roster;
    };
}

#endif // JXMPP_ROSTERMEMORYSTORAGE_H
