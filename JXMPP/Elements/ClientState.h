#ifndef JXMPP_CLIENTSTATE_H
#define JXMPP_CLIENTSTATE_H

/*
 * Copyright (c) 2017 Tarun Gupta.
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API ClientState : public Payload {
        public:
            typedef std::shared_ptr<ClientState> ref;

        public:
            enum class ClientStateType {Active, Inactive};
            ClientState(ClientStateType state = ClientStateType::Active) : state_(state)  {

            }

            ClientStateType getClientState() const { return state_; }
            void setClientState(ClientStateType state) {state_ = state;}

        private:
            ClientStateType state_;
    };
}

#endif // JXMPP_CLIENTSTATE_H
