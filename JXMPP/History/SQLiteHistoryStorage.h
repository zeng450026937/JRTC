#ifndef JXMPP_SQLITEHISTORYSTORAGE_H
#define JXMPP_SQLITEHISTORYSTORAGE_H

#include <thread>

#include <boost/filesystem/path.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/History/HistoryStorage.h>

struct sqlite3;

namespace JXMPP {
    class JXMPP_API SQLiteHistoryStorage : public HistoryStorage {
        public:
            SQLiteHistoryStorage(const boost::filesystem::path& file);
            ~SQLiteHistoryStorage();

            void addMessage(const HistoryMessage& message);
            ContactsMap getContacts(const JID& selfJID, HistoryMessage::Type type, const std::string& keyword) const;
            std::vector<HistoryMessage> getMessagesFromDate(const JID& selfJID, const JID& contactJID, HistoryMessage::Type type, const boost::gregorian::date& date) const;
            std::vector<HistoryMessage> getMessagesFromNextDate(const JID& selfJID, const JID& contactJID, HistoryMessage::Type type, const boost::gregorian::date& date) const;
            std::vector<HistoryMessage> getMessagesFromPreviousDate(const JID& selfJID, const JID& contactJID, HistoryMessage::Type type, const boost::gregorian::date& date) const;
            boost::posix_time::ptime getLastTimeStampFromMUC(const JID& selfJID, const JID& mucJID) const;

        private:
            void run();
            boost::gregorian::date getNextDateWithLogs(const JID& selfJID, const JID& contactJID, HistoryMessage::Type type, const boost::gregorian::date& date, bool reverseOrder) const;
            long long getIDForJID(const JID&);
            long long addJID(const JID&);

            boost::optional<JID> getJIDFromID(long long id) const;
            boost::optional<long long> getIDFromJID(const JID& jid) const;

            sqlite3* db_;
            std::thread* thread_;
    };
}

#endif // JXMPP_SQLITEHISTORYSTORAGE_H
