#ifndef JXMPP_PUBSUBITEM_H
#define JXMPP_PUBSUBITEM_H

#include <memory>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubItem : public Payload {
        public:

            PubSubItem();

            virtual ~PubSubItem();

            const std::vector< std::shared_ptr<Payload> >& getData() const {
                return data;
            }

            void setData(const std::vector< std::shared_ptr<Payload> >& value) {
                this->data = value ;
            }

            void addData(std::shared_ptr<Payload> value) {
                this->data.push_back(value);
            }

            const std::string& getID() const {
                return id;
            }

            void setID(const std::string& value) {
                this->id = value ;
            }


        private:
            std::vector< std::shared_ptr<Payload> > data;
            std::string id;
    };
}

#endif // JXMPP_PUBSUBITEM_H
