#ifndef JXMPP_NULLNATTRAVERSALINTERFACE_H
#define JXMPP_NULLNATTRAVERSALINTERFACE_H

#include <boost/optional.hpp>

#include <JXMPP/Network/NATTraversalInterface.h>

namespace JXMPP {
    class NullNATTraversalInterface : public NATTraversalInterface {
        public:
            virtual bool isAvailable() {
                return true;
            }

            virtual boost::optional<HostAddress> getPublicIP() {
                return boost::optional<HostAddress>();
            }

            virtual boost::optional<NATPortMapping> addPortForward(int, int) {
                return boost::optional<NATPortMapping>();
            }

            virtual bool removePortForward(const NATPortMapping&) {
                return false;
            }
    };
}

#endif // JXMPP_NULLNATTRAVERSALINTERFACE_H
