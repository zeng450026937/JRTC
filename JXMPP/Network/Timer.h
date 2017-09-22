#ifndef JXMPP_TIMER_H
#define JXMPP_TIMER_H

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    /**
     * A class for triggering an event after a given period.
     */
    class JXMPP_API Timer {
        public:
            typedef std::shared_ptr<Timer> ref;

            virtual ~Timer();

            /**
             * Starts the timer.
             *
             * After the given period, onTick() will be called.
             */
            virtual void start() = 0;

            /**
             * Cancels the timer.
             *
             * If the timer was started, onTick() will no longer be called.
             */
            virtual void stop() = 0;

            /**
             * Emitted when the timer expires.
             */
            boost::signals2::signal<void ()> onTick;
    };
}

#endif // JXMPP_TIMER_H
