#ifndef JXMPP_BODY_H
#define JXMPP_BODY_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API Body : public Payload {
        public:
            Body(const std::string& text = "") : text_(text) {
            }

            void setText(const std::string& text) {
                text_ = text;
            }

            const std::string& getText() const {
                return text_;
            }

        private:
            std::string text_;
    };
}

#endif // JXMPP_BODY_H
