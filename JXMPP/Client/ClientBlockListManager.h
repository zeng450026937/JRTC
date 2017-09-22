#ifndef JXMPP_CLIENTBLOCKLISTMANAGER_H
#define JXMPP_CLIENTBLOCKLISTMANAGER_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Client/BlockList.h>
#include <JXMPP/Client/BlockListImpl.h>
#include <JXMPP/Elements/BlockListPayload.h>
#include <JXMPP/Elements/BlockPayload.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Elements/UnblockPayload.h>
#include <JXMPP/Queries/GenericRequest.h>
#include <JXMPP/Queries/SetResponder.h>

namespace JXMPP {
    class IQRouter;

    class JXMPP_API ClientBlockListManager {
        public:
            ClientBlockListManager(IQRouter *iqRouter);
            ~ClientBlockListManager();

            /**
             * Returns the blocklist.
             */
            std::shared_ptr<BlockList> getBlockList();

            /**
             * Get the blocklist from the server.
             */
            std::shared_ptr<BlockList> requestBlockList();

            GenericRequest<BlockPayload>::ref createBlockJIDRequest(const JID& jid);
            GenericRequest<BlockPayload>::ref createBlockJIDsRequest(const std::vector<JID>& jids);

            GenericRequest<UnblockPayload>::ref createUnblockJIDRequest(const JID& jid);
            GenericRequest<UnblockPayload>::ref createUnblockJIDsRequest(const std::vector<JID>& jids);
            GenericRequest<UnblockPayload>::ref createUnblockAllRequest();

        private:
            void handleBlockListReceived(std::shared_ptr<BlockListPayload> payload, ErrorPayload::ref);

        private:
            IQRouter* iqRouter;
            std::shared_ptr<SetResponder<BlockPayload> > blockResponder;
            std::shared_ptr<SetResponder<UnblockPayload> > unblockResponder;
            std::shared_ptr<BlockListImpl> blockList;
    };
}

#endif // JXMPP_CLIENTBLOCKLISTMANAGER_H
