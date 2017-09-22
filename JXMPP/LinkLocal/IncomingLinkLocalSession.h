#ifndef JXMPP_INCOMINGLINKLOCALSESSION_H
#define JXMPP_INCOMINGLINKLOCALSESSION_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/Session/Session.h>

namespace JXMPP {
    class ProtocolHeader;
    class XMLParserFactory;
    class ToplevelElement;
    class PayloadParserFactoryCollection;
    class PayloadSerializerCollection;

    class JXMPP_API IncomingLinkLocalSession : public Session {
        public:
            IncomingLinkLocalSession(
                    const JID& localJID,
                    std::shared_ptr<Connection> connection,
                    PayloadParserFactoryCollection* payloadParserFactories,
                    PayloadSerializerCollection* payloadSerializers,
                    XMLParserFactory* xmlParserFactory);

            boost::signals2::signal<void ()> onSessionStarted;

        private:
            void handleElement(std::shared_ptr<ToplevelElement>);
            void handleStreamStart(const ProtocolHeader&);
            void setInitialized();
            bool isInitialized() const {
                return initialized;
            }

            bool initialized;
    };
}

#endif // JXMPP_INCOMINGLINKLOCALSESSION_H
