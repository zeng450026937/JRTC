#ifndef JXMPP_NATTRAVERSALINTERFACE_H
#define JXMPP_NATTRAVERSALINTERFACE_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/NATPortMapping.h>

namespace JXMPP {
    class JXMPP_API NATTraversalInterface {
        public:
            virtual ~NATTraversalInterface();

            virtual bool isAvailable() = 0;

            virtual boost::optional<HostAddress> getPublicIP() = 0;
            virtual boost::optional<NATPortMapping> addPortForward(int localPort, int publicPort) = 0;
            virtual bool removePortForward(const NATPortMapping&) = 0;
    };
}

#endif // JXMPP_NATTRAVERSALINTERFACE_H
