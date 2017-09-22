#include <JXMPP/Base/SimpleIDGenerator.h>

namespace JXMPP {

SimpleIDGenerator::SimpleIDGenerator() {
}

SimpleIDGenerator::~SimpleIDGenerator() {
}

std::string SimpleIDGenerator::generateID() {
    bool carry = true;
    size_t i = 0;
    while (carry && i < currentID.size()) {
        char c = currentID[i];
        if (c >= 'z') {
            currentID[i] = 'a';
        }
        else {
            currentID[i] = c+1;
            carry = false;
        }
        ++i;
    }
    if (carry) {
        currentID += 'a';
    }
    return currentID;
}

}
