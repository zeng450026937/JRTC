#ifndef JXMPP_MINIUPNPINTERFACE_H
#define JXMPP_MINIUPNPINTERFACE_H

#include <memory>

#include <boost/noncopyable.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Network/NATPortMapping.h>
#include <JXMPP/Network/NATTraversalInterface.h>

namespace JXMPP {
    class MiniUPnPInterface : public NATTraversalInterface, boost::noncopyable {
        public:
            MiniUPnPInterface();
            virtual ~MiniUPnPInterface();

            virtual bool isAvailable();

            boost::optional<HostAddress> getPublicIP();
            boost::optional<NATPortMapping> addPortForward(int localPort, int publicPort);
            bool removePortForward(const NATPortMapping&);

        private:
            struct Private;
            const std::unique_ptr<Private> p;
    };
}

#endif // JXMPP_MINIUPNPINTERFACE_H
