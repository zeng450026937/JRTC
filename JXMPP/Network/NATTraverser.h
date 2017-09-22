#ifndef JXMPP_NATTRAVERSER_H
#define JXMPP_NATTRAVERSER_H

#include <memory>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class NATTraversalGetPublicIPRequest;
    class NATTraversalForwardPortRequest;
    class NATTraversalRemovePortForwardingRequest;

    class JXMPP_API NATTraverser {
        public:
            virtual ~NATTraverser();

            virtual std::shared_ptr<NATTraversalGetPublicIPRequest> createGetPublicIPRequest() = 0;
            virtual std::shared_ptr<NATTraversalForwardPortRequest> createForwardPortRequest(int localPort, int publicPort) = 0;
            virtual std::shared_ptr<NATTraversalRemovePortForwardingRequest> createRemovePortForwardingRequest(int localPort, int publicPort) = 0;
    };
}

#endif // JXMPP_NATTRAVERSER_H
