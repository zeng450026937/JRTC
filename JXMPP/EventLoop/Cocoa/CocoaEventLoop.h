#ifndef JXMPP_COCOAEVENTLOOP_H
#define JXMPP_COCOAEVENTLOOP_H

#include <mutex>

#include <JXMPP/EventLoop/EventLoop.h>

namespace JXMPP {
    class CocoaEventLoop : public EventLoop {
        public:
            CocoaEventLoop();
            virtual ~CocoaEventLoop();

            void handleNextCocoaEvent();

        protected:
            virtual void eventPosted();

        private:
            bool isEventInCocoaEventLoop_;
            std::recursive_mutex isEventInCocoaEventLoopMutex_;
    };
}

#endif // JXMPP_COCOAEVENTLOOP_H
