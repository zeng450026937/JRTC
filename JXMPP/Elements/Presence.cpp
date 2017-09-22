#include <JXMPP/Elements/Presence.h>

#include <JXMPP/Elements/Priority.h>
#include <JXMPP/Elements/Status.h>

namespace JXMPP {

Presence::Presence() : type_(Available) /*, showType_(Online)*/ {
}

Presence::Presence(const std::string& status) : type_(Available) {
    setStatus(status);
}

Presence::~Presence() {
}

int Presence::getPriority() const {
    std::shared_ptr<Priority> priority(getPayload<Priority>());
    return (priority ? priority->getPriority() : 0);
}

void Presence::setPriority(int priority) {
    updatePayload(std::make_shared<Priority>(priority));
}

std::string Presence::getStatus() const {
    std::shared_ptr<Status> status(getPayload<Status>());
    if (status) {
        return status->getText();
    }
    return "";
}

void Presence::setStatus(const std::string& status) {
    updatePayload(std::make_shared<Status>(status));
}

}
