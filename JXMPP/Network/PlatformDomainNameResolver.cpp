#include <JXMPP/Network/PlatformDomainNameResolver.h>

#include <algorithm>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include <boost/bind.hpp>

#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/IDN/IDNConverter.h>
#include <JXMPP/Network/DomainNameAddressQuery.h>
#include <JXMPP/Network/HostAddress.h>
#include <JXMPP/Network/HostAddressPort.h>
#include <JXMPP/Network/PlatformDomainNameAddressQuery.h>
#include <JXMPP/Network/PlatformDomainNameServiceQuery.h>

using namespace JXMPP;

namespace JXMPP {

PlatformDomainNameResolver::PlatformDomainNameResolver(IDNConverter* idnConverter, EventLoop* eventLoop) : idnConverter(idnConverter), eventLoop(eventLoop), stopRequested(false) {
    thread = new std::thread(boost::bind(&PlatformDomainNameResolver::run, this));
}

PlatformDomainNameResolver::~PlatformDomainNameResolver() {
    stopRequested = true;
    addQueryToQueue(std::shared_ptr<PlatformDomainNameQuery>());
    thread->join();
    delete thread;
}

std::shared_ptr<DomainNameServiceQuery> PlatformDomainNameResolver::createServiceQuery(const std::string& serviceLookupPrefix, const std::string& domain) {
    boost::optional<std::string> encodedDomain = idnConverter->getIDNAEncoded(domain);
    std::string result;
    if (encodedDomain) {
        result = serviceLookupPrefix + *encodedDomain;
    }
    return std::make_shared<PlatformDomainNameServiceQuery>(result, eventLoop, this);
}

std::shared_ptr<DomainNameAddressQuery> PlatformDomainNameResolver::createAddressQuery(const std::string& name) {
    return std::make_shared<PlatformDomainNameAddressQuery>(idnConverter->getIDNAEncoded(name), eventLoop, this);
}

void PlatformDomainNameResolver::run() {
    while (!stopRequested) {
        PlatformDomainNameQuery::ref query;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            while (queue.empty()) {
                queueNonEmpty.wait(lock);
            }
            query = queue.front();
            queue.pop_front();
        }
        // Check whether we don't have a non-null query (used to stop the
        // resolver)
        if (query) {
            query->runBlocking();
        }
    }
}

void PlatformDomainNameResolver::addQueryToQueue(PlatformDomainNameQuery::ref query) {
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        queue.push_back(query);
    }
    queueNonEmpty.notify_one();
}

}
