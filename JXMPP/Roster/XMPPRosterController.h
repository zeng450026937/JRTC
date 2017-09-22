#ifndef JXMPP_XMPPROSTERCONTROLLER_H
#define JXMPP_XMPPROSTERCONTROLLER_H

#include <memory>
#include <string>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Elements/RosterPayload.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Roster/RosterPushResponder.h>

namespace JXMPP {
    class IQRouter;
    class XMPPRosterImpl;
    class RosterStorage;

    class JXMPP_API XMPPRosterController {
        public:
            XMPPRosterController(IQRouter *iqRouter, XMPPRosterImpl* xmppRoster, RosterStorage* storage);
            ~XMPPRosterController();

            void requestRoster();

            void setUseVersioning(bool b) {
                useVersioning = b;
            }

        private:
            void handleRosterReceived(std::shared_ptr<RosterPayload> rosterPayload, bool initial, std::shared_ptr<RosterPayload> previousRoster);
            void saveRoster(const std::string& version);

        private:
            IQRouter* iqRouter_;
            RosterPushResponder rosterPushResponder_;
            XMPPRosterImpl* xmppRoster_;
            RosterStorage* rosterStorage_;
            bool useVersioning;
    };
}

#endif // JXMPP_XMPPROSTERCONTROLLER_H
