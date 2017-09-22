#include <JXMPP/Jingle/AbstractJingleSessionListener.h>

#include <JXMPP/Base/Log.h>

using namespace JXMPP;

void AbstractJingleSessionListener::handleSessionAcceptReceived(const JingleContentID&, std::shared_ptr<JingleDescription>, std::shared_ptr<JingleTransportPayload>) {
    JXMPP_LOG(warning) << "Unimplemented" << std::endl;
}

void AbstractJingleSessionListener::handleSessionInfoReceived(std::shared_ptr<JinglePayload>) {
    JXMPP_LOG(warning) << "Unimplemented" << std::endl;
}

void AbstractJingleSessionListener::handleSessionTerminateReceived(boost::optional<JinglePayload::Reason>) {
    JXMPP_LOG(warning) << "Unimplemented" << std::endl;
}

void AbstractJingleSessionListener::handleTransportAcceptReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>) {
    JXMPP_LOG(warning) << "Unimplemented" << std::endl;
}

void AbstractJingleSessionListener::handleTransportInfoReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>) {
    JXMPP_LOG(warning) << "Unimplemented" << std::endl;
}

void AbstractJingleSessionListener::handleTransportRejectReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>) {
    JXMPP_LOG(warning) << "Unimplemented" << std::endl;
}

void AbstractJingleSessionListener::handleTransportReplaceReceived(const JingleContentID&, std::shared_ptr<JingleTransportPayload>) {
    JXMPP_LOG(warning) << "Unimplemented" << std::endl;
}

void AbstractJingleSessionListener::handleTransportInfoAcknowledged(const std::string&) {
}
