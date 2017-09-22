#ifndef JXMPP_HISTORYSTORAGE_H
#define JXMPP_HISTORYSTORAGE_H

#include <map>
#include <set>
#include <vector>

#include <boost/date_time/gregorian/gregorian_types.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/History/HistoryMessage.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    typedef std::map<JID, std::set<boost::gregorian::date> > ContactsMap;

    class JXMPP_API HistoryStorage {
        /**
         * Messages are stored using localtime timestamps.
         */
        public:
            virtual ~HistoryStorage() {}

            virtual void addMessage(const HistoryMessage& message) = 0;
            virtual std::vector<HistoryMessage> getMessagesFromDate(const JID& selfJID, const JID& contactJID, HistoryMessage::Type type, const boost::gregorian::date& date) const = 0;
            virtual std::vector<HistoryMessage> getMessagesFromNextDate(const JID& selfJID, const JID& contactJID, HistoryMessage::Type type, const boost::gregorian::date& date) const = 0;
            virtual std::vector<HistoryMessage> getMessagesFromPreviousDate(const JID& selfJID, const JID& contactJID, HistoryMessage::Type type, const boost::gregorian::date& date) const = 0;
            virtual ContactsMap getContacts(const JID& selfJID, HistoryMessage::Type type, const std::string& keyword) const = 0;
            virtual boost::posix_time::ptime getLastTimeStampFromMUC(const JID& selfJID, const JID& mucJID) const = 0;
    };
}

#endif // JXMPP_HISTORYSTORAGE_H
