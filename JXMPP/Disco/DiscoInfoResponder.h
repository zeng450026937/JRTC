#ifndef JXMPP_DISCOINFORESPONDER_H
#define JXMPP_DISCOINFORESPONDER_H

#include <map>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Queries/GetResponder.h>

namespace JXMPP {
    class IQRouter;

    class JXMPP_API DiscoInfoResponder : public GetResponder<DiscoInfo> {
        public:
            DiscoInfoResponder(IQRouter* router);

            void clearDiscoInfo();
            void setDiscoInfo(const DiscoInfo& info);
            void setDiscoInfo(const std::string& node, const DiscoInfo& info);

        private:
            virtual bool handleGetRequest(const JID& from, const JID& to, const std::string& id, std::shared_ptr<DiscoInfo> payload);

        private:
            DiscoInfo info_;
            std::map<std::string, DiscoInfo> nodeInfo_;
    };
}

#endif // JXMPP_DISCOINFORESPONDER_H
