#ifndef JXMPP_IQCHANNEL_H
#define JXMPP_IQCHANNEL_H

#include <memory>
#include <string>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IQ.h>

namespace JXMPP {
    class JXMPP_API IQChannel {
        public:
            virtual ~IQChannel();

            virtual void sendIQ(std::shared_ptr<IQ>) = 0;
            virtual std::string getNewIQID() = 0;

            virtual bool isAvailable() const = 0;

            boost::signals2::signal<void (std::shared_ptr<IQ>)> onIQReceived;
    };
}

#endif // JXMPP_IQCHANNEL_H
