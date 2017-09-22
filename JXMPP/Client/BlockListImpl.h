#ifndef JXMPP_BLOCKLISTIMPL_H
#define JXMPP_BLOCKLISTIMPL_H

#include <JXMPP/Client/BlockList.h>

namespace JXMPP {
    class BlockListImpl : public BlockList {
        public:
            BlockListImpl();

            virtual State getState() const {
                return state;
            }

            void setState(State state);

            virtual const std::vector<JID>& getItems() const {
                return items;
            }

            void setItems(const std::vector<JID>& newItems);
            void addItem(const JID& item);
            void removeItem(const JID& item);
            void addItems(const std::vector<JID>& items);
            void removeItems(const std::vector<JID>& items);
            void removeAllItems();

        private:
            State state;
            std::vector<JID> items;
    };
}

#endif // JXMPP_BLOCKLISTIMPL_H
