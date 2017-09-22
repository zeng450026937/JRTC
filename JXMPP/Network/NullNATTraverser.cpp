#include <JXMPP/Network/NullNATTraverser.h>

#include <memory>

#include <boost/bind.hpp>

#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/Network/NATTraversalForwardPortRequest.h>
#include <JXMPP/Network/NATTraversalGetPublicIPRequest.h>
#include <JXMPP/Network/NATTraversalRemovePortForwardingRequest.h>

namespace JXMPP {

class NullNATTraversalGetPublicIPRequest : public NATTraversalGetPublicIPRequest {
    public:
        NullNATTraversalGetPublicIPRequest(EventLoop* eventLoop) : eventLoop(eventLoop) {
        }

        virtual void start() {
            eventLoop->postEvent(boost::bind(boost::ref(onResult), boost::optional<HostAddress>()));
        }

        virtual void stop() {
        }

    private:
        EventLoop* eventLoop;
};

class NullNATTraversalForwardPortRequest : public NATTraversalForwardPortRequest {
    public:
        NullNATTraversalForwardPortRequest(EventLoop* eventLoop) : eventLoop(eventLoop) {
        }

        virtual void start() {
            eventLoop->postEvent(boost::bind(boost::ref(onResult), boost::optional<NATPortMapping>()));
        }

        virtual void stop() {
        }

    private:
        EventLoop* eventLoop;
};

class NullNATTraversalRemovePortForwardingRequest : public NATTraversalRemovePortForwardingRequest {
    public:
        NullNATTraversalRemovePortForwardingRequest(EventLoop* eventLoop) : eventLoop(eventLoop) {
        }

        virtual void start() {
            eventLoop->postEvent(boost::bind(boost::ref(onResult), boost::optional<bool>(true)));
        }

        virtual void stop() {
        }

    private:
        EventLoop* eventLoop;
};

NullNATTraverser::NullNATTraverser(EventLoop* eventLoop) : eventLoop(eventLoop) {
}

std::shared_ptr<NATTraversalGetPublicIPRequest> NullNATTraverser::createGetPublicIPRequest() {
    return std::make_shared<NullNATTraversalGetPublicIPRequest>(eventLoop);
}

std::shared_ptr<NATTraversalForwardPortRequest> NullNATTraverser::createForwardPortRequest(int, int) {
    return std::make_shared<NullNATTraversalForwardPortRequest>(eventLoop);
}

std::shared_ptr<NATTraversalRemovePortForwardingRequest> NullNATTraverser::createRemovePortForwardingRequest(int, int) {
    return std::make_shared<NullNATTraversalRemovePortForwardingRequest>(eventLoop);
}

}
