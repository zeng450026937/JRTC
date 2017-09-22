#include <JXMPP/FileTransfer/IBBReceiveSession.h>

#include <cassert>

#include <boost/bind.hpp>

#include <JXMPP/Base/Log.h>
#include <JXMPP/FileTransfer/BytestreamException.h>
#include <JXMPP/FileTransfer/IBBRequest.h>
#include <JXMPP/Queries/IQRouter.h>
#include <JXMPP/Queries/SetResponder.h>

namespace JXMPP {

class IBBReceiveSession::IBBResponder : public SetResponder<IBB> {
    public:
        IBBResponder(IBBReceiveSession* session, IQRouter* router) : SetResponder<IBB>(router), session(session), sequenceNumber(0), receivedSize(0) {
            setFinal(false);
        }

        virtual bool handleSetRequest(const JID& from, const JID&, const std::string& id, IBB::ref ibb) {
            if (from == session->from && ibb->getStreamID() == session->id) {
                if (ibb->getAction() == IBB::Data) {
                    if (sequenceNumber == ibb->getSequenceNumber()) {
                        session->bytestream->write(ibb->getData());
                        receivedSize += ibb->getData().size();
                        sequenceNumber++;
                        sendResponse(from, id, IBB::ref());
                        if (receivedSize >= session->size) {
                            if (receivedSize > session->size) {
                                JXMPP_LOG(warning) << "Received more data than expected";
                            }
                            session->finish(boost::optional<FileTransferError>());
                        }
                    }
                    else {
                        JXMPP_LOG(warning) << "Received data out of order";
                        sendError(from, id, ErrorPayload::NotAcceptable, ErrorPayload::Cancel);
                        session->finish(FileTransferError(FileTransferError::ClosedError));
                    }
                }
                else if (ibb->getAction() == IBB::Open) {
                    JXMPP_LOG(debug) << "IBB open received";
                    sendResponse(from, id, IBB::ref());
                }
                else if (ibb->getAction() == IBB::Close) {
                    JXMPP_LOG(debug) << "IBB close received";
                    sendResponse(from, id, IBB::ref());
                    session->finish(FileTransferError(FileTransferError::ClosedError));
                }
                return true;
            }
            JXMPP_LOG(debug) << "wrong from/sessionID: " << from << " == " << session->from << " / " <<ibb->getStreamID() << " == " << session->id;
            return false;
        }

    private:
        IBBReceiveSession* session;
        int sequenceNumber;
        unsigned long long receivedSize;
};


IBBReceiveSession::IBBReceiveSession(
        const std::string& id,
        const JID& from,
        const JID& to,
        unsigned long long size,
        std::shared_ptr<WriteBytestream> bytestream,
        IQRouter* router) :
            id(id),
            from(from),
            to(to),
            size(size),
            bytestream(bytestream),
            router(router),
            active(false) {
    assert(!id.empty());
    assert(from.isValid());
    responder = new IBBResponder(this, router);
}

IBBReceiveSession::~IBBReceiveSession() {
    if (active) {
        JXMPP_LOG(warning) << "Session still active";
    }
    delete responder;
}

void IBBReceiveSession::start() {
    JXMPP_LOG(debug) << "receive session started";
    active = true;
    responder->start();
}

void IBBReceiveSession::stop() {
    JXMPP_LOG(debug) << "receive session stopped";
    responder->stop();
    if (active) {
        if (router->isAvailable()) {
            IBBRequest::create(to, from, IBB::createIBBClose(id), router)->send();
        }
        finish(boost::optional<FileTransferError>());
    }
}

void IBBReceiveSession::finish(boost::optional<FileTransferError> error) {
    active = false;
    onFinished(error);
}

}
