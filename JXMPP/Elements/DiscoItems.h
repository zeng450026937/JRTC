#ifndef JXMPP_DISCOITEMS_H
#define JXMPP_DISCOITEMS_H

#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    /**
     * Service discovery disco#items from XEP-0030.
     */
    class JXMPP_API DiscoItems : public Payload {
        public:
            /**
             * A single result item.
             */
            class Item {
                public:
                    Item(const std::string& name, const JID& jid, const std::string& node="") : name_(name), jid_(jid), node_(node) {
                    }

                    const std::string& getName() const {
                        return name_;
                    }

                    const std::string& getNode() const {
                        return node_;
                    }

                    const JID& getJID() const {
                        return jid_;
                    }

                private:
                    std::string name_;
                    JID jid_;
                    std::string node_;
            };

            DiscoItems() {
            }

            const std::string& getNode() const {
                return node_;
            }

            void setNode(const std::string& node) {
                node_ = node;
            }

            const std::vector<Item>& getItems() const {
                return items_;
            }

            void addItem(const Item& item) {
                items_.push_back(item);
            }

        private:
            std::string node_;
            std::vector<Item> items_;
    };
}

#endif // JXMPP_DISCOITEMS_H
