#ifndef JXMPP_SOCKS5BYTESTREAMPROXYFINDER_H
#define JXMPP_SOCKS5BYTESTREAMPROXYFINDER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */





#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Disco/DiscoServiceWalker.h>
#include <JXMPP/Elements/S5BProxyRequest.h>

namespace JXMPP {

class JID;
class IQRouter;

/*
 * This class is designed to find possible SOCKS5 bytestream proxies which are used for peer-to-peer data transfers in
 * restrictive environments.
 */
class JXMPP_API SOCKS5BytestreamProxyFinder {
    public:
        SOCKS5BytestreamProxyFinder(const JID& service, IQRouter *iqRouter);
        ~SOCKS5BytestreamProxyFinder();

        void start();
        void stop();

        boost::signals2::signal<void(std::vector<std::shared_ptr<S5BProxyRequest> >)> onProxiesFound;

    private:
        void sendBytestreamQuery(const JID&);

        void handleServiceFound(const JID&, std::shared_ptr<DiscoInfo>);
        void handleProxyResponse(std::shared_ptr<GenericRequest<S5BProxyRequest> > requester, std::shared_ptr<S5BProxyRequest>, ErrorPayload::ref);
        void handleWalkEnded();

    private:
        JID service;
        IQRouter* iqRouter;
        std::shared_ptr<DiscoServiceWalker> serviceWalker;
        std::vector<S5BProxyRequest::ref> proxyHosts;
        std::set<std::shared_ptr<GenericRequest<S5BProxyRequest> > > pendingRequests;
};

}

#endif // JXMPP_SOCKS5BYTESTREAMPROXYFINDER_H
