#ifndef JXMPP_PAYLOAD_H
#define JXMPP_PAYLOAD_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Element.h>

namespace JXMPP {
    class JXMPP_API Payload : public Element {
        public:
            typedef std::shared_ptr<Payload> ref;
        public:
            Payload() {}
            JXMPP_DEFAULT_COPY_CONSTRUCTOR(Payload)
            virtual ~Payload();

            JXMPP_DEFAULT_COPY_ASSIGMNENT_OPERATOR(Payload)
    };
}

#endif // JXMPP_PAYLOAD_H
