#ifndef JXMPP_CHATSTATENOTIFIER_H
#define JXMPP_CHATSTATENOTIFIER_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ChatState.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class StanzaChannel;
    class EntityCapsProvider;
    class TimerFactory;
    class Timer;


    class JXMPP_API ChatStateNotifier {
        public:
            ChatStateNotifier(StanzaChannel* stanzaChannel, const JID& contact, EntityCapsProvider* entityCapsManager, TimerFactory* timerFactory, int idleTimeInMilliSecs);
            ~ChatStateNotifier();

            void setContact(const JID& contact);

            void addChatStateRequest(Message::ref message);

            void setUserIsTyping();
            void userSentMessage();
            void userCancelledNewMessage();

            void receivedMessageFromContact(bool hasActiveElement);
            void setContactIsOnline(bool online);

        private:
            void userBecameIdleWhileTyping();
            bool contactShouldReceiveStates();
            void changeState(ChatState::ChatStateType type);
            void handleCapsChanged(const JID& contact);

        private:
            StanzaChannel* stanzaChannel_;
            EntityCapsProvider* entityCapsManager_;
            JID contact_;
            bool contactHas85Caps_;
            bool contactHasSentActive_;
            bool userIsTyping_;
            bool contactIsOnline_;
            std::shared_ptr<Timer> idleTimer_;

    };
}

#endif // JXMPP_CHATSTATENOTIFIER_H
