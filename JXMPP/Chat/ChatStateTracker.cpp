#include <JXMPP/Chat/ChatStateTracker.h>

namespace JXMPP {
ChatStateTracker::ChatStateTracker() {
    currentState_ = ChatState::Gone;
}

void ChatStateTracker::handleMessageReceived(std::shared_ptr<Message> message) {
    if (message->getType() == Message::Error) {
        return;
    }
    std::shared_ptr<ChatState> statePayload = message->getPayload<ChatState>();
    if (statePayload) {
        changeState(statePayload->getChatState());;
    }
}

void ChatStateTracker::handlePresenceChange(std::shared_ptr<Presence> newPresence) {
    if (newPresence->getType() == Presence::Unavailable) {
        onChatStateChange(ChatState::Gone);
    }
}

void ChatStateTracker::changeState(ChatState::ChatStateType state) {
    if (state != currentState_) {
        currentState_ = state;
        onChatStateChange(state);
    }
}

}
