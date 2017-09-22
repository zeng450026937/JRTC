#ifndef JXMPP_PUBSUBEVENTITEM_H
#define JXMPP_PUBSUBEVENTITEM_H

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubEventItem : public Payload {
        public:

            PubSubEventItem();

            virtual ~PubSubEventItem();

            const boost::optional< std::string >& getNode() const {
                return node;
            }

            void setNode(const boost::optional< std::string >& value) {
                this->node = value ;
            }

            const boost::optional< std::string >& getPublisher() const {
                return publisher;
            }

            void setPublisher(const boost::optional< std::string >& value) {
                this->publisher = value ;
            }

            const std::vector< std::shared_ptr<Payload> >& getData() const {
                return data;
            }

            void setData(const std::vector< std::shared_ptr<Payload> >& value) {
                this->data = value ;
            }

            void addData(std::shared_ptr<Payload> value) {
                this->data.push_back(value);
            }

            const boost::optional< std::string >& getID() const {
                return id;
            }

            void setID(const boost::optional< std::string >& value) {
                this->id = value ;
            }


        private:
            boost::optional< std::string > node;
            boost::optional< std::string > publisher;
            std::vector< std::shared_ptr<Payload> > data;
            boost::optional< std::string > id;
    };
}

#endif // JXMPP_PUBSUBEVENTITEM_H
