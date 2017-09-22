#ifndef JXMPP_ROSTERSTORAGE_H
#define JXMPP_ROSTERSTORAGE_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RosterPayload.h>

namespace JXMPP {
    class JXMPP_API RosterStorage {
        public:
            virtual ~RosterStorage();

            virtual std::shared_ptr<RosterPayload> getRoster() const = 0;
            virtual void setRoster(std::shared_ptr<RosterPayload>) = 0;
    };
}

#endif // JXMPP_ROSTERSTORAGE_H
