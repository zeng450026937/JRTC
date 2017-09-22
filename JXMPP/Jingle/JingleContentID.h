#ifndef JXMPP_JINGLECONTENTID_H
#define JXMPP_JINGLECONTENTID_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleContentPayload.h>

namespace JXMPP {
    class JXMPP_API JingleContentID {
        public:
            JingleContentID(const std::string& name, JingleContentPayload::Creator creator) : name(name), creator(creator) {
            }

            const std::string getName() const {
                return this->name;
            }

            JingleContentPayload::Creator getCreator() const {
                return this->creator;
            }

        private:
            std::string name;
            JingleContentPayload::Creator creator;
    };
}

#endif // JXMPP_JINGLECONTENTID_H
