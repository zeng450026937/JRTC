#ifndef JXMPP_DUMMYEVENTLOOP_H
#define JXMPP_DUMMYEVENTLOOP_H

#include <atomic>

#include <JXMPP/Base/API.h>
#include <JXMPP/EventLoop/EventLoop.h>

namespace JXMPP {
    class JXMPP_API DummyEventLoop : public EventLoop {
        public:
            DummyEventLoop();
            virtual ~DummyEventLoop();

            void processEvents();

            bool hasEvents();

            virtual void eventPosted();

        private:
            std::atomic<bool> hasEvents_ = ATOMIC_VAR_INIT(false);
    };
}

#endif // JXMPP_DUMMYEVENTLOOP_H
