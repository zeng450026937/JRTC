#ifndef JXMPP_DISCOSERVICEWALKER_H
#define JXMPP_DISCOSERVICEWALKER_H

#include <memory>
#include <set>
#include <string>
#include <vector>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Disco/GetDiscoInfoRequest.h>
#include <JXMPP/Disco/GetDiscoItemsRequest.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Elements/DiscoItems.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class IQRouter;
    /**
     * Recursively walk service discovery trees to find all services offered.
     * This stops on any disco item that's not reporting itself as a server.
     */
    class JXMPP_API DiscoServiceWalker {
        public:
            DiscoServiceWalker(const JID& service, IQRouter* iqRouter, size_t maxSteps = 200);

            /**
             * Start the walk.
             *
             * Call this exactly once.
             */
            void beginWalk();

            /**
             * End the walk.
             */
            void endWalk();

            bool isActive() const {
                return active_;
            }

            /** Emitted for each service found. */
            boost::signals2::signal<void(const JID&, std::shared_ptr<DiscoInfo>)> onServiceFound;

            /** Emitted when walking is aborted. */
            boost::signals2::signal<void()> onWalkAborted;

            /** Emitted when walking is complete.*/
            boost::signals2::signal<void()> onWalkComplete;

        private:
            void walkNode(const JID& jid);
            void markNodeCompleted(const JID& jid);
            void handleDiscoInfoResponse(std::shared_ptr<DiscoInfo> info, ErrorPayload::ref error, GetDiscoInfoRequest::ref request);
            void handleDiscoItemsResponse(std::shared_ptr<DiscoItems> items, ErrorPayload::ref error, GetDiscoItemsRequest::ref request);
            void handleDiscoError(const JID& jid, ErrorPayload::ref error);

        private:
            JID service_;
            IQRouter* iqRouter_;
            size_t maxSteps_;
            bool active_;
            std::set<JID> servicesBeingSearched_;
            std::set<JID> searchedServices_;
            std::set<GetDiscoInfoRequest::ref> pendingDiscoInfoRequests_;
            std::set<GetDiscoItemsRequest::ref> pendingDiscoItemsRequests_;
    };
}

#endif // JXMPP_DISCOSERVICEWALKER_H
