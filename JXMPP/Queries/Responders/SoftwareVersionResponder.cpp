#include <JXMPP/Queries/Responders/SoftwareVersionResponder.h>

#include <memory>

#include <JXMPP/Queries/IQRouter.h>

namespace JXMPP {

SoftwareVersionResponder::SoftwareVersionResponder(IQRouter* router) : GetResponder<SoftwareVersion>(router) {
}

void SoftwareVersionResponder::setVersion(const std::string& client, const std::string& version, const std::string& os) {
    this->client = client;
    this->version = version;
    this->os = os;
}

bool SoftwareVersionResponder::handleGetRequest(const JID& from, const JID&, const std::string& id, std::shared_ptr<SoftwareVersion>) {
    sendResponse(from, id, std::make_shared<SoftwareVersion>(client, version, os));
    return true;
}

}
