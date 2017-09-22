#ifndef JXMPP_XMPPSERIALIZER_H
#define JXMPP_XMPPSERIALIZER_H

#include <memory>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamType.h>
#include <JXMPP/Elements/ToplevelElement.h>
#include <JXMPP/Serializer/ElementSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;
    class ProtocolHeader;

    class JXMPP_API XMPPSerializer {
        public:
            XMPPSerializer(PayloadSerializerCollection*, StreamType type, bool setExplictNSonTopLevelElements);

            std::string serializeHeader(const ProtocolHeader&) const;
            SafeByteArray serializeElement(std::shared_ptr<ToplevelElement> stanza) const;
            std::string serializeFooter() const;

        private:
            std::string getDefaultNamespace() const;

        private:
            StreamType type_;
            std::vector< std::shared_ptr<ElementSerializer> > serializers_;
    };
}

#endif // JXMPP_XMPPSERIALIZER_H
