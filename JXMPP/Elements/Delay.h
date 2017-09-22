#ifndef JXMPP_DELAY_H
#define JXMPP_DELAY_H

#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API Delay : public Payload {
        public:
            Delay() {}
            Delay(const boost::posix_time::ptime& time, const JID& from = JID()) : time_(time), from_(from) {}

            const boost::posix_time::ptime& getStamp() const {return time_;}
            void setStamp(const boost::posix_time::ptime& time) {time_ = time;}

            const boost::optional<JID>& getFrom() const {return from_;}
            void setFrom(const JID& from) {from_ = from;}

        private:
            boost::posix_time::ptime time_;
            boost::optional<JID> from_;
    };
}

#endif // JXMPP_DELAY_H
