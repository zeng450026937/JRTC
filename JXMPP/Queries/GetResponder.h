#ifndef JXMPP_GETRESPONDER_H
#define JXMPP_GETRESPONDER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Queries/Responder.h>

namespace JXMPP {
    template<typename T>
    class JXMPP_API GetResponder : public Responder<T> {
        public:
            GetResponder(IQRouter* router) : Responder<T>(router) {}

        private:
            virtual bool handleSetRequest(const JID&, const JID&, const std::string&, std::shared_ptr<T>) { return false; }
    };
}

#endif // JXMPP_GETRESPONDER_H
