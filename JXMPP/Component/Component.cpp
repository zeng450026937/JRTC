#include <JXMPP/Component/Component.h>

#include <JXMPP/Queries/Responders/SoftwareVersionResponder.h>

namespace JXMPP {

Component::Component(const JID& jid, const std::string& secret, NetworkFactories* networkFactories) : CoreComponent(jid, secret, networkFactories) {
    softwareVersionResponder = new SoftwareVersionResponder(getIQRouter());
    softwareVersionResponder->start();
}

Component::~Component() {
    softwareVersionResponder->stop();
    delete softwareVersionResponder;
}

void Component::setSoftwareVersion(const std::string& name, const std::string& version) {
    softwareVersionResponder->setVersion(name, version);
}

}
