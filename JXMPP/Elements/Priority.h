#ifndef JXMPP_PRIORITY_H
#define JXMPP_PRIORITY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API Priority : public Payload {
        public:
            Priority(int priority = 0) : priority_(priority) {
            }

            void setPriority(int priority) {
                priority_ = priority;
            }

            int getPriority() const {
                return priority_;
            }

        private:
            int priority_;
    };
}

#endif // JXMPP_PRIORITY_H
