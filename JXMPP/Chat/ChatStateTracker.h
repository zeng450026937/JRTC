#ifndef JXMPP_CHATSTATETRACKER_H
#define JXMPP_CHATSTATETRACKER_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ChatState.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/Elements/Presence.h>

namespace JXMPP {
    class JXMPP_API ChatStateTracker {
        public:
            ChatStateTracker();
            void handleMessageReceived(std::shared_ptr<Message> message);
            void handlePresenceChange(std::shared_ptr<Presence> newPresence);
            boost::signals2::signal<void (ChatState::ChatStateType)> onChatStateChange;
        private:
            void changeState(ChatState::ChatStateType state);
            ChatState::ChatStateType currentState_;
    };
}

#endif // JXMPP_CHATSTATETRACKER_H
