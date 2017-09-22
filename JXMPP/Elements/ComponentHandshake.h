#ifndef JXMPP_COMPONENTHANDSHAKE_H
#define JXMPP_COMPONENTHANDSHAKE_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API ComponentHandshake : public ToplevelElement {
        public:
            typedef std::shared_ptr<ComponentHandshake> ref;

            ComponentHandshake(const std::string& data = "") : data(data) {
            }

            void setData(const std::string& d) {
                data = d;
            }

            const std::string& getData() const {
                return data;
            }

        private:
            std::string data;
    };
}

#endif // JXMPP_COMPONENTHANDSHAKE_H
