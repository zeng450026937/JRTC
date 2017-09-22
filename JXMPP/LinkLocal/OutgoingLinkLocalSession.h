#ifndef JXMPP_OUTGOINGLINKLOCALSESSION_H
#define JXMPP_OUTGOINGLINKLOCALSESSION_H

#include <memory>
#include <vector>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Session/Session.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadSerializerCollection;
    class ToplevelElement;
    class XMLParserFactory;

    class JXMPP_API OutgoingLinkLocalSession : public Session {
        public:
            OutgoingLinkLocalSession(
                    const JID& localJID,
                    const JID& remoteJID,
                    std::shared_ptr<Connection> connection,
                    PayloadParserFactoryCollection* payloadParserFactories,
                    PayloadSerializerCollection* payloadSerializers,
                    XMLParserFactory* xmlParserFactory);

            void queueElement(std::shared_ptr<ToplevelElement> element);

        private:
            void handleSessionStarted();
            void handleElement(std::shared_ptr<ToplevelElement>);
            void handleStreamStart(const ProtocolHeader&);

        private:
            std::vector<std::shared_ptr<ToplevelElement> > queuedElements_;
    };
}

#endif // JXMPP_OUTGOINGLINKLOCALSESSION_H
