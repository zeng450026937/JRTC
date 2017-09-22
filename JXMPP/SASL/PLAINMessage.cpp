#include <JXMPP/SASL/PLAINMessage.h>

#include <JXMPP/Base/Concat.h>

namespace JXMPP {

PLAINMessage::PLAINMessage(const std::string& authcid, const SafeByteArray& password, const std::string& authzid) : authcid(authcid), authzid(authzid), password(password) {
}

PLAINMessage::PLAINMessage(const SafeByteArray& value) {
    size_t i = 0;
    while (i < value.size() && value[i] != '\0') {
        authzid += static_cast<char>(value[i]);
        ++i;
    }
    if (i == value.size()) {
        return;
    }
    ++i;
    while (i < value.size() && value[i] != '\0') {
        authcid += static_cast<char>(value[i]);
        ++i;
    }
    if (i == value.size()) {
        authcid = "";
        return;
    }
    ++i;
    while (i < value.size()) {
        password.push_back(value[i]);
        ++i;
    }
}

SafeByteArray PLAINMessage::getValue() const {
    return concat(createSafeByteArray(authzid), createSafeByteArray('\0'), createSafeByteArray(authcid), createSafeByteArray('\0'), password);
}

}
