#ifndef JXMPP_CARBONSENABLE_H
#define JXMPP_CARBONSENABLE_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API CarbonsEnable : public Payload {
        public:
            typedef std::shared_ptr<CarbonsEnable> ref;

        public:
            virtual ~CarbonsEnable();
    };
}

#endif // JXMPP_CARBONSENABLE_H
