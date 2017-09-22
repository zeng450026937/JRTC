#ifndef JXMPP_PLATFORMNATTRAVERSALWORKER_H
#define JXMPP_PLATFORMNATTRAVERSALWORKER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <condition_variable>
#include <deque>
#include <mutex>
#include <thread>

#include <boost/logic/tribool.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Atomic.h>
#include <JXMPP/Network/HostAddressPort.h>
#include <JXMPP/Network/NATTraverser.h>
#include <JXMPP/Network/NullNATTraversalInterface.h>

namespace JXMPP {
    class EventLoop;
    class NATTraversalGetPublicIPRequest;
    class NATTraversalForwardPortRequest;
    class NATTraversalRemovePortForwardingRequest;
    class PlatformNATTraversalRequest;
    class NATPMPInterface;
    class MiniUPnPInterface;
    class NATTraversalInterface;

    class JXMPP_API PlatformNATTraversalWorker : public NATTraverser {
            friend class PlatformNATTraversalRequest;

        public:
            PlatformNATTraversalWorker(EventLoop* eventLoop);
            virtual ~PlatformNATTraversalWorker();

            std::shared_ptr<NATTraversalGetPublicIPRequest> createGetPublicIPRequest();
            std::shared_ptr<NATTraversalForwardPortRequest> createForwardPortRequest(int localPort, int publicPort);
            std::shared_ptr<NATTraversalRemovePortForwardingRequest> createRemovePortForwardingRequest(int localPort, int publicPort);

        private:
            NATTraversalInterface* getNATTraversalInterface() const;
            void addRequestToQueue(std::shared_ptr<PlatformNATTraversalRequest>);
            void start();
            void stop();

            EventLoop* getEventLoop() const {
                return eventLoop;
            }

        private:
            EventLoop* eventLoop;
            Atomic<bool> stopRequested;
            std::thread* thread;
            std::deque<std::shared_ptr<PlatformNATTraversalRequest> > queue;
            std::mutex queueMutex;
            std::condition_variable queueNonEmpty;

            NullNATTraversalInterface* nullNATTraversalInterface;
            mutable boost::logic::tribool natPMPSupported;
            mutable NATPMPInterface* natPMPInterface;
            mutable boost::logic::tribool miniUPnPSupported;
            mutable MiniUPnPInterface* miniUPnPInterface;
    };
}

#endif // JXMPP_PLATFORMNATTRAVERSALWORKER_H
