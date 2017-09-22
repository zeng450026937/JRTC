#ifndef JXMPP_MUCADMINPAYLOAD_H
#define JXMPP_MUCADMINPAYLOAD_H

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCItem.h>
#include <JXMPP/Elements/MUCOccupant.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API MUCAdminPayload : public Payload {
        public:
            typedef std::shared_ptr<MUCAdminPayload> ref;


            MUCAdminPayload() {
            }

            void addItem(const MUCItem& item) {items_.push_back(item);}

            const std::vector<MUCItem>& getItems() const {return items_;}

        private:
            std::vector<MUCItem> items_;
    };
}

#endif // JXMPP_MUCADMINPAYLOAD_H
