#ifndef JXMPP_SESSIONTRACER_H
#define JXMPP_SESSIONTRACER_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Session/Session.h>

namespace JXMPP {
    class JXMPP_API SessionTracer {
        public:
            SessionTracer(std::shared_ptr<Session> session);

        private:
            void printData(char direction, const SafeByteArray& data);

            std::shared_ptr<Session> session;
    };
}

#endif // JXMPP_SESSIONTRACER_H
