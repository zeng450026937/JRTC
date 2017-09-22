#ifndef JXMPP_ROSTERPUSHRESPONDER_H
#define JXMPP_ROSTERPUSHRESPONDER_H

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RosterPayload.h>
#include <JXMPP/Queries/SetResponder.h>

namespace JXMPP {
    class JXMPP_API RosterPushResponder : public SetResponder<RosterPayload> {
        public:
            RosterPushResponder(IQRouter* router) : SetResponder<RosterPayload>(router) {}

        public:
            boost::signals2::signal<void (std::shared_ptr<RosterPayload>)> onRosterReceived;

        private:
            virtual bool handleSetRequest(const JID& from, const JID&, const std::string& id, std::shared_ptr<RosterPayload> payload) {
                if (getIQRouter()->isAccountJID(from)) {
                    onRosterReceived(payload);
                    sendResponse(from, id, std::shared_ptr<RosterPayload>());
                }
                else {
                    sendError(from, id, ErrorPayload::NotAuthorized, ErrorPayload::Cancel);
                }
                return true;
            }
    };
}

#endif // JXMPP_ROSTERPUSHRESPONDER_H
