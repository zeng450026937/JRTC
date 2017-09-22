#include <JXMPP/LinkLocal/DNSSD/PlatformDNSSDQuerierFactory.h>

#if defined(HAVE_BONJOUR)
#include <JXMPP/LinkLocal/DNSSD/Bonjour/BonjourQuerier.h>
#elif defined(HAVE_AVAHI)
#include <JXMPP/LinkLocal/DNSSD/Avahi/AvahiQuerier.h>
#endif


namespace JXMPP {

PlatformDNSSDQuerierFactory::PlatformDNSSDQuerierFactory(EventLoop* eventLoop) : eventLoop(eventLoop) {
}

std::shared_ptr<DNSSDQuerier> PlatformDNSSDQuerierFactory::createQuerier() {
#if defined(HAVE_BONJOUR)
    return std::make_shared<BonjourQuerier>(eventLoop);
#elif defined(HAVE_AVAHI)
    return std::make_shared<AvahiQuerier>(eventLoop);
#else
    (void)eventLoop;
    return std::shared_ptr<DNSSDQuerier>();
#endif
}

bool PlatformDNSSDQuerierFactory::canCreate() {
#if defined(HAVE_BONJOUR) || defined(HAVE_AVAHI)
    return true;
#else
    return false;
#endif
}

}
