// FIXME: This example is not complete yet

#include <iostream>

#include <JXMPP/EventLoop/SimpleEventLoop.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDBrowseQuery.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDQuerier.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDResolveServiceQuery.h>
#include <JXMPP/LinkLocal/DNSSD/PlatformDNSSDQuerierFactory.h>

using namespace JXMPP;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Invalid parameters" << std::endl;
        return -1;
    }

    SimpleEventLoop eventLoop;
    PlatformDNSSDQuerierFactory factory(&eventLoop);
    std::shared_ptr<DNSSDQuerier> querier = factory.createQuerier();
    querier->start();

    if (std::string(argv[1]) == "browse") {
        std::shared_ptr<DNSSDBrowseQuery> browseQuery = querier->createBrowseQuery();
        browseQuery->startBrowsing();
        eventLoop.run();
        browseQuery->stopBrowsing();
    }
    else if (std::string(argv[1]) == "resolve-service") {
        if (argc < 5) {
            std::cerr << "Invalid parameters" << std::endl;
            return -1;
        }
        std::shared_ptr<DNSSDResolveServiceQuery> resolveQuery = querier->createResolveServiceQuery(DNSSDServiceID(argv[2], argv[3], argv[4]));
        resolveQuery->start();
        eventLoop.run();
        std::cerr << "Done running" << std::endl;
        resolveQuery->stop();
    }

    querier->stop();
}
