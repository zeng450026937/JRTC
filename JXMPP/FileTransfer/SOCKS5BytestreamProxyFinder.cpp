/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/FileTransfer/SOCKS5BytestreamProxyFinder.h>

#include <memory>

#include <boost/bind.hpp>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Elements/S5BProxyRequest.h>
#include <JXMPP/Queries/GenericRequest.h>
#include <JXMPP/Queries/IQRouter.h>

namespace JXMPP {

SOCKS5BytestreamProxyFinder::SOCKS5BytestreamProxyFinder(const JID& service, IQRouter *iqRouter) : service(service), iqRouter(iqRouter) {
}

SOCKS5BytestreamProxyFinder::~SOCKS5BytestreamProxyFinder() {
}

void SOCKS5BytestreamProxyFinder::start() {
    serviceWalker = std::make_shared<DiscoServiceWalker>(service, iqRouter);
    serviceWalker->onServiceFound.connect(boost::bind(&SOCKS5BytestreamProxyFinder::handleServiceFound, this, _1, _2));
    serviceWalker->onWalkComplete.connect(boost::bind(&SOCKS5BytestreamProxyFinder::handleWalkEnded, this));
    serviceWalker->beginWalk();
}

void SOCKS5BytestreamProxyFinder::stop() {
    for (auto&& requester : pendingRequests) {
        requester->onResponse.disconnect(boost::bind(&SOCKS5BytestreamProxyFinder::handleProxyResponse, this, requester, _1, _2));
    }

    serviceWalker->endWalk();
    serviceWalker->onServiceFound.disconnect(boost::bind(&SOCKS5BytestreamProxyFinder::handleServiceFound, this, _1, _2));
    serviceWalker->onWalkComplete.disconnect(boost::bind(&SOCKS5BytestreamProxyFinder::handleWalkEnded, this));
    serviceWalker.reset();
}

void SOCKS5BytestreamProxyFinder::sendBytestreamQuery(const JID& jid) {
    S5BProxyRequest::ref proxyRequest = std::make_shared<S5BProxyRequest>();
    std::shared_ptr<GenericRequest<S5BProxyRequest> > request = std::make_shared<GenericRequest<S5BProxyRequest> >(IQ::Get, jid, proxyRequest, iqRouter);
    request->onResponse.connect(boost::bind(&SOCKS5BytestreamProxyFinder::handleProxyResponse, this, request, _1, _2));
    pendingRequests.insert(request);
    request->send();
}

void SOCKS5BytestreamProxyFinder::handleServiceFound(const JID& jid, std::shared_ptr<DiscoInfo> discoInfo) {
    if (discoInfo->hasFeature(DiscoInfo::Bytestream)) {
        sendBytestreamQuery(jid);
    }
}

void SOCKS5BytestreamProxyFinder::handleWalkEnded() {
    if (pendingRequests.empty()) {
        onProxiesFound(proxyHosts);
    }
}

void SOCKS5BytestreamProxyFinder::handleProxyResponse(std::shared_ptr<GenericRequest<S5BProxyRequest> > requester, std::shared_ptr<S5BProxyRequest> request, ErrorPayload::ref error) {
    requester->onResponse.disconnect(boost::bind(&SOCKS5BytestreamProxyFinder::handleProxyResponse, this, requester, _1, _2));
    pendingRequests.erase(requester);
    if (error) {
        JXMPP_LOG(debug) << "ERROR" << std::endl;
    } else {
        if (request) {
            JXMPP_LOG(debug) << "add request" << std::endl;
            proxyHosts.push_back(request);
        }
    }
    if (pendingRequests.empty() && !serviceWalker->isActive()) {
        onProxiesFound(proxyHosts);
    }
}

}
