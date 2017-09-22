#ifndef JXMPP_WHITESPACEPINGLAYER_H
#define JXMPP_WHITESPACEPINGLAYER_H

#include <memory>

#include <boost/noncopyable.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/StreamStack/StreamLayer.h>

namespace JXMPP {
    class Timer;
    class TimerFactory;

    class JXMPP_API WhitespacePingLayer : public StreamLayer, boost::noncopyable {
        public:
            WhitespacePingLayer(TimerFactory* timerFactory);
            virtual ~WhitespacePingLayer();

            void setActive();
            void setInactive();
            void writeData(const SafeByteArray& data);
            void handleDataRead(const SafeByteArray& data);

            bool getIsActive() const {
                return isActive;
            }

        private:
            void handleTimerTick();

        private:
            bool isActive;
            std::shared_ptr<Timer> timer;
    };
}

#endif // JXMPP_WHITESPACEPINGLAYER_H
