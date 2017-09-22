#include <JXMPP/FileTransfer/FailingTransportSession.h>

#include <JXMPP/Base/Log.h>

namespace JXMPP {

FailingTransportSession::~FailingTransportSession() {
}

void FailingTransportSession::start() {
    JXMPP_LOG(error) << "Trying to start failing transport." << std::endl;
    onFinished(FileTransferError(FileTransferError::PeerError));
}

void FailingTransportSession::stop() {
}

}
