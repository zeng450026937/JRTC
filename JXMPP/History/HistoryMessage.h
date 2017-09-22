#ifndef JXMPP_HISTORYMESSAGE_H
#define JXMPP_HISTORYMESSAGE_H

#include <boost/date_time/posix_time/posix_time_types.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API HistoryMessage {
        public:
            enum Type {
                Chat = 0,
                Groupchat = 1,
                PrivateMessage = 2
            };

            HistoryMessage(
                const std::string& message,
                const JID& fromJID,
                const JID& toJID,
                Type type,
                const boost::posix_time::ptime& time,
                int utcOffset = 0) :
                    message_(message),
                    fromJID_(fromJID),
                    toJID_(toJID),
                    type_(type),
                    time_(time),
                    utcOffset_(utcOffset) {
            }

            const std::string& getMessage() const {
                return message_;
            }

            const JID& getFromJID() const {
                return fromJID_;
            }

            const JID& getToJID() const {
                return toJID_;
            }

            Type getType() const {
                return type_;
            }

            boost::posix_time::ptime getTime() const {
                return time_;
            }

            int getOffset() const {
                return utcOffset_;
            }

            bool operator==(const HistoryMessage& o) const {
                return message_ == o.message_ && fromJID_ == o.fromJID_ && toJID_ == o.toJID_ && type_ == o.type_ && time_ == o.time_;
            }

        private:
            std::string message_;
            JID fromJID_;
            JID toJID_;
            Type type_;
            boost::posix_time::ptime time_;
            int utcOffset_;
    };
}

#endif // JXMPP_HISTORYMESSAGE_H
