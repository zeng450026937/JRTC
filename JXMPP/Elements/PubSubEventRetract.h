#ifndef JXMPP_PUBSUBEVENTRETRACT_H
#define JXMPP_PUBSUBEVENTRETRACT_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubEventRetract : public Payload {
        public:

            PubSubEventRetract();

            virtual ~PubSubEventRetract();

            const std::string& getID() const {
                return id;
            }

            void setID(const std::string& value) {
                this->id = value ;
            }


        private:
            std::string id;
    };
}

#endif // JXMPP_PUBSUBEVENTRETRACT_H
