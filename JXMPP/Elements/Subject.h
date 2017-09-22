#ifndef JXMPP_SUBJECT_H
#define JXMPP_SUBJECT_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API Subject : public Payload {
        public:
            Subject(const std::string& text = "") : text_(text) {
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

#endif // JXMPP_SUBJECT_H
