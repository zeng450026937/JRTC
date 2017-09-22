#ifndef JXMPP_CHATSTATE_H
#define JXMPP_CHATSTATE_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API ChatState : public Payload {
        public:
            typedef std::shared_ptr<ChatState> ref;

        public:
            enum ChatStateType {Active, Composing, Paused, Inactive, Gone};
            ChatState(ChatStateType state = Active) {
                state_ = state;
            }

            ChatStateType getChatState() const { return state_; }
            void setChatState(ChatStateType state) {state_ = state;}

        private:
            ChatStateType state_;
    };
}

#endif // JXMPP_CHATSTATE_H
