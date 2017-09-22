#ifndef JXMPP_NULLNATTRAVERSER_H
#define JXMPP_NULLNATTRAVERSER_H

#include <JXMPP/Network/NATTraverser.h>

namespace JXMPP {
    class EventLoop;

    class NullNATTraverser : public NATTraverser {
        public:
            NullNATTraverser(EventLoop* eventLoop);

            std::shared_ptr<NATTraversalGetPublicIPRequest> createGetPublicIPRequest();
            std::shared_ptr<NATTraversalForwardPortRequest> createForwardPortRequest(int localPort, int publicPort);
            std::shared_ptr<NATTraversalRemovePortForwardingRequest> createRemovePortForwardingRequest(int localPort, int publicPort);

        private:
            EventLoop* eventLoop;
    };
}

#endif // JXMPP_NULLNATTRAVERSER_H
