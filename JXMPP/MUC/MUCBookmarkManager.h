#ifndef JXMPP_MUCBOOKMARKMANAGER_H
#define JXMPP_MUCBOOKMARKMANAGER_H

#include <memory>
#include <vector>

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/Storage.h>
#include <JXMPP/MUC/MUCBookmark.h>

namespace JXMPP {
    class IQRouter;

    class JXMPP_API MUCBookmarkManager {
        public:
            MUCBookmarkManager(IQRouter* iqRouter);

            void addBookmark(const MUCBookmark& bookmark);
            void removeBookmark(const MUCBookmark& bookmark);
            void replaceBookmark(const MUCBookmark& oldBookmark, const MUCBookmark& newBookmark);

            const std::vector<MUCBookmark>& getBookmarks() const;

        public:
            boost::signals2::signal<void (const MUCBookmark&)> onBookmarkAdded;
            boost::signals2::signal<void (const MUCBookmark&)> onBookmarkRemoved;
            /**
             * When server bookmarks are ready to be used (request response has been received).
             */
            boost::signals2::signal<void ()> onBookmarksReady;

        private:
            bool containsEquivalent(const std::vector<MUCBookmark>& list, const MUCBookmark& bookmark);
            void handleBookmarksReceived(std::shared_ptr<Storage> payload, ErrorPayload::ref error);
            void flush();

        private:
            bool ready_;
            std::vector<MUCBookmark> bookmarks_;
            IQRouter* iqRouter_;
            std::shared_ptr<Storage> storage;
    };
}

#endif // JXMPP_MUCBOOKMARKMANAGER_H
