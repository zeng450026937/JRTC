#ifndef JXMPP_STATUSSHOWSERIALIZER_H
#define JXMPP_STATUSSHOWSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StatusShow.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API StatusShowSerializer : public GenericPayloadSerializer<StatusShow> {
        public:
            StatusShowSerializer() : GenericPayloadSerializer<StatusShow>() {}

            virtual std::string serializePayload(std::shared_ptr<StatusShow> statusShow)  const {
                if (statusShow->getType () == StatusShow::Online || statusShow->getType() == StatusShow::None) {
                    return "";
                }
                else {
                    std::string result("<show>");
                    switch (statusShow->getType()) {
                        case StatusShow::Away: result += "away"; break;
                        case StatusShow::XA: result += "xa"; break;
                        case StatusShow::FFC: result += "chat"; break;
                        case StatusShow::DND: result += "dnd"; break;
                        case StatusShow::Online: assert(false); break;
                        case StatusShow::None: assert(false); break;
                    }
                    result += "</show>";
                    return result;
                }
            }
    };
}

#endif // JXMPP_STATUSSHOWSERIALIZER_H
