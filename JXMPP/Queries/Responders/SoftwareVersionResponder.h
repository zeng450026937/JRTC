#ifndef JXMPP_SOFTWAREVERSIONRESPONDER_H
#define JXMPP_SOFTWAREVERSIONRESPONDER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/SoftwareVersion.h>
#include <JXMPP/Queries/GetResponder.h>

namespace JXMPP {
    class IQRouter;

    class JXMPP_API SoftwareVersionResponder : public GetResponder<SoftwareVersion> {
        public:
            SoftwareVersionResponder(IQRouter* router);

            void setVersion(const std::string& client, const std::string& version, const std::string& os = "");

        private:
            virtual bool handleGetRequest(const JID& from, const JID& to, const std::string& id, std::shared_ptr<SoftwareVersion> payload);

        private:
            std::string client;
            std::string version;
            std::string os;
    };
}

#endif // JXMPP_SOFTWAREVERSIONRESPONDER_H
