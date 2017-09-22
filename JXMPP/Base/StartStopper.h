#ifndef JXMPP_STARTSTOPPER_H
#define JXMPP_STARTSTOPPER_H

namespace JXMPP {
    template<typename T> class StartStopper {
        public:
            StartStopper(T* target) : target(target) {
                target->start();
            }

            ~StartStopper() {
                target->stop();
            }

        private:
            T* target;
    };
}

#endif // JXMPP_STARTSTOPPER_H
