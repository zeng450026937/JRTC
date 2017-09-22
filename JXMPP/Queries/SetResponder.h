#ifndef JXMPP_SETRESPONDER_H
#define JXMPP_SETRESPONDER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Queries/Responder.h>

namespace JXMPP {
    template<typename T>
    class JXMPP_API SetResponder : public Responder<T> {
        public:
            SetResponder(IQRouter* router) : Responder<T>(router) {}

        private:
            virtual bool handleGetRequest(const JID&, const JID&, const std::string&, std::shared_ptr<T>) { return false; }
    };
}

#endif // JXMPP_SETRESPONDER_H
