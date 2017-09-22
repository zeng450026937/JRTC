#ifndef JXMPP_JINGLEDESCRIPTION_H
#define JXMPP_JINGLEDESCRIPTION_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API JingleDescription : public Payload {
        public:
            typedef std::shared_ptr<JingleDescription> ref;
    };
}

#endif // JXMPP_JINGLEDESCRIPTION_H
