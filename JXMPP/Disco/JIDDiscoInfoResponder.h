#ifndef JXMPP_JIDDISCOINFORESPONDER_H
#define JXMPP_JIDDISCOINFORESPONDER_H

#include <map>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Queries/GetResponder.h>

namespace JXMPP {
    class IQRouter;

    class JXMPP_API JIDDiscoInfoResponder : public GetResponder<DiscoInfo> {
        public:
            JIDDiscoInfoResponder(IQRouter* router);

            void clearDiscoInfo(const JID& jid);
            void setDiscoInfo(const JID& jid, const DiscoInfo& info);
            void setDiscoInfo(const JID& jid, const std::string& node, const DiscoInfo& info);

        private:
            virtual bool handleGetRequest(const JID& from, const JID& to, const std::string& id, std::shared_ptr<DiscoInfo> payload);

        private:
            struct JIDDiscoInfo {
                DiscoInfo discoInfo;
                std::map<std::string, DiscoInfo> nodeDiscoInfo;
            };
            typedef std::map<JID, JIDDiscoInfo> JIDDiscoInfoMap;
            JIDDiscoInfoMap info;
    };
}

#endif // JXMPP_JIDDISCOINFORESPONDER_H
