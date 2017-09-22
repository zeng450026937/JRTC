#ifndef JXMPP_LAST_H
#define JXMPP_LAST_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API Last : public Payload {
        public:
            Last(int seconds = 0) : seconds_(seconds) {}

            int getSeconds() const {return seconds_;}
            void setSeconds(int seconds) {seconds_ = seconds;}

        private:
            int seconds_;
    };
}

#endif // JXMPP_LAST_H
