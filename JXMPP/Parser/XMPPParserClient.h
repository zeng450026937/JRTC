#ifndef JXMPP_XMPPPARSERCLIENT_H
#define JXMPP_XMPPPARSERCLIENT_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {

    class ProtocolHeader;

    class JXMPP_API XMPPParserClient {
        public:
            virtual ~XMPPParserClient();

            virtual void handleStreamStart(const ProtocolHeader&) = 0;
            virtual void handleElement(std::shared_ptr<ToplevelElement>) = 0;
            virtual void handleStreamEnd() = 0;
    };
}

#endif // JXMPP_XMPPPARSERCLIENT_H
