#ifndef JXMPP_STANZAACKSERIALIZER_H
#define JXMPP_STANZAACKSERIALIZER_H

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StanzaAck.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API StanzaAckSerializer : public GenericElementSerializer<StanzaAck> {
        public:
            StanzaAckSerializer() : GenericElementSerializer<StanzaAck>() {
            }

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element) const {
                StanzaAck::ref stanzaAck(std::dynamic_pointer_cast<StanzaAck>(element));
                assert(stanzaAck->isValid());
                XMLElement result("a", "urn:xmpp:sm:2");
                result.setAttribute("h", std::string(boost::lexical_cast<std::string>(stanzaAck->getHandledStanzasCount())));
                return createSafeByteArray(result.serialize());
            }
    };
}

#endif // JXMPP_STANZAACKSERIALIZER_H
