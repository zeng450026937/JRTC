#ifndef JXMPP_SIMPLEEVENTLOOP_H
#define JXMPP_SIMPLEEVENTLOOP_H

#include <condition_variable>
#include <mutex>

#include <JXMPP/Base/API.h>
#include <JXMPP/EventLoop/EventLoop.h>

namespace JXMPP {
    class JXMPP_API SimpleEventLoop : public EventLoop {
        public:
            SimpleEventLoop();
            virtual ~SimpleEventLoop();

            void run() {
                doRun(false);
            }

            void runUntilEvents() {
                doRun(true);
            }

            void runOnce();

            void stop();

        protected:
            virtual void eventPosted();

        private:
            void doRun(bool breakAfterEvents);
            void doStop();

        private:
            bool isRunning_;

            bool eventAvailable_;
            std::mutex eventAvailableMutex_;
            std::condition_variable eventAvailableCondition_;
    };
}

#endif // JXMPP_SIMPLEEVENTLOOP_H
