#ifndef JXMPP_THREAD_H
#define JXMPP_THREAD_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API Thread : public Payload {
        public:
            Thread(const std::string& text = "", const std::string& parent = "");
            virtual ~Thread();
            void setText(const std::string& text);
            const std::string& getText() const;
            void setParent(const std::string& parent);
            const std::string& getParent() const;

        private:
            std::string text_;
            std::string parent_;
    };
}

#endif // JXMPP_THREAD_H
