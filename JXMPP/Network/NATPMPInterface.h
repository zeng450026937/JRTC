#ifndef JXMPP_NATPMPINTERFACE_H
#define JXMPP_NATPMPINTERFACE_H

#include <memory>

#include <boost/noncopyable.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Network/NATPortMapping.h>
#include <JXMPP/Network/NATTraversalInterface.h>

namespace JXMPP {
    class NATPMPInterface : public NATTraversalInterface, boost::noncopyable {
        public:
            NATPMPInterface();
            virtual ~NATPMPInterface();

            virtual bool isAvailable();

            virtual boost::optional<HostAddress> getPublicIP();
            virtual boost::optional<NATPortMapping> addPortForward(int localPort, int publicPort);
            virtual bool removePortForward(const NATPortMapping&);

        private:
            struct Private;
            const std::unique_ptr<Private> p;
    };
}

#endif // JXMPP_NATPMPINTERFACE_H
