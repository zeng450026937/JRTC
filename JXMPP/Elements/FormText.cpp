#include <JXMPP/Elements/FormText.h>

namespace JXMPP {

FormText::FormText() {
}

FormText::~FormText() {
}

void FormText::setTextString(const std::string& text) {
    text_ = text;
}

const std::string& FormText::getTextString() const {
    return text_;
}

}
