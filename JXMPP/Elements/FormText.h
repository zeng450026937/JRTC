#ifndef JXMPP_FORMTEXT_H
#define JXMPP_FORMTEXT_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>

namespace JXMPP {

    class JXMPP_API FormText{

        public:
            typedef std::shared_ptr<FormText> text;
            FormText();
            virtual ~FormText();
            void setTextString(const std::string& text);
            const std::string& getTextString() const;

        private:
            std::string text_;
    };
}

#endif // JXMPP_FORMTEXT_H
