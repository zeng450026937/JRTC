#ifndef JXMPP_CARBONSPRIVATE_H
#define JXMPP_CARBONSPRIVATE_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API CarbonsPrivate : public Payload {
        public:
            typedef std::shared_ptr<CarbonsPrivate> ref;

        public:
            virtual ~CarbonsPrivate();
    };
}

#endif // JXMPP_CARBONSPRIVATE_H
