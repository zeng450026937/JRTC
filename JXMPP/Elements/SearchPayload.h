#ifndef JXMPP_SEARCHPAYLOAD_H
#define JXMPP_SEARCHPAYLOAD_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    /**
     * XEP-0055 search payload.
     */
    class JXMPP_API SearchPayload : public Payload {
        public:
            typedef std::shared_ptr<SearchPayload> ref;

            struct Item {
                std::string first;
                std::string last;
                std::string nick;
                std::string email;
                JID jid;
            };

            SearchPayload() {}

            Form::ref getForm() const { return form; }
            void setForm(Form::ref f) { form = f; }

            const boost::optional<std::string>& getInstructions() const {
                return instructions;
            }

            const boost::optional<std::string>& getNick() const {
                return nick;
            }

            const boost::optional<std::string>& getFirst() const {
                return first;
            }

            const boost::optional<std::string>& getLast() const {
                return last;
            }

            const boost::optional<std::string>& getEMail() const {
                return email;
            }

            void setInstructions(const std::string& v) {
                this->instructions = v;
            }

            void setNick(const std::string& v) {
                this->nick = v;
            }

            void setFirst(const std::string& v) {
                this->first = v;
            }

            void setLast(const std::string& v) {
                this->last = v;
            }

            void setEMail(const std::string& v) {
                this->email = v;
            }

            const std::vector<Item>& getItems() const {
                return items;
            }

            void addItem(const Item& item) {
                items.push_back(item);
            }

        private:
            Form::ref form;
            boost::optional<std::string> instructions;
            boost::optional<std::string> nick;
            boost::optional<std::string> first;
            boost::optional<std::string> last;
            boost::optional<std::string> email;
            std::vector<Item> items;
    };
}

#endif // JXMPP_SEARCHPAYLOAD_H
