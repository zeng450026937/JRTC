#ifndef JXMPP_LASTSERIALIZER_H
#define JXMPP_LASTSERIALIZER_H

#include <boost/lexical_cast.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Last.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API LastSerializer : public GenericPayloadSerializer<Last> {
        public:
            LastSerializer() : GenericPayloadSerializer<Last>() {}

            virtual std::string serializePayload(std::shared_ptr<Last> last)  const {
                return "<query xmlns='jabber:iq:last' seconds='" + boost::lexical_cast<std::string>(last->getSeconds()) + "'/>";
            }
    };
}

#endif // JXMPP_LASTSERIALIZER_H
