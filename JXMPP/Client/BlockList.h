#ifndef JXMPP_BLOCKLIST_H
#define JXMPP_BLOCKLIST_H

#include <vector>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API BlockList {
        public:
            enum State {
                Init,
                Requesting,
                Available,
                Error
            };
            virtual ~BlockList();

            virtual State getState() const = 0;

            virtual const std::vector<JID>& getItems() const = 0;

            bool isBlocked(const JID& jid) const;

        public:
            boost::signals2::signal<void ()> onStateChanged;
            boost::signals2::signal<void (const JID&)> onItemAdded;
            boost::signals2::signal<void (const JID&)> onItemRemoved;
    };
}

#endif // JXMPP_BLOCKLIST_H
