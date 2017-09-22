#ifndef JXMPP_COMPONENT_H
#define JXMPP_COMPONENT_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Component/CoreComponent.h>

namespace JXMPP {
    class SoftwareVersionResponder;

    /**
     * Provides the core functionality for writing XMPP component software.
     *
     * Besides connecting to an XMPP server, this class also provides interfaces for
     * performing most component tasks on the XMPP network.
     */
    class JXMPP_API Component : public CoreComponent {
        public:
            Component(const JID& jid, const std::string& secret, NetworkFactories* networkFactories);
            virtual ~Component();

            /**
             * Sets the software version of the client.
             *
             * This will be used to respond to version queries from other entities.
             */
            void setSoftwareVersion(const std::string& name, const std::string& version);

        private:
            SoftwareVersionResponder* softwareVersionResponder;
    };
}

#endif // JXMPP_COMPONENT_H
