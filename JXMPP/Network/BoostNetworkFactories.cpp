#include <JXMPP/Network/BoostNetworkFactories.h>

#include <JXMPP/Crypto/CryptoProvider.h>
#include <JXMPP/Crypto/PlatformCryptoProvider.h>
#include <JXMPP/IDN/IDNConverter.h>
#include <JXMPP/IDN/PlatformIDNConverter.h>
#include <JXMPP/Network/BoostConnectionFactory.h>
#include <JXMPP/Network/BoostConnectionServerFactory.h>
#include <JXMPP/Network/BoostTimerFactory.h>
#include <JXMPP/Network/NullNATTraverser.h>
#include <JXMPP/Network/PlatformNATTraversalWorker.h>
#include <JXMPP/Network/PlatformNetworkEnvironment.h>
#include <JXMPP/Network/PlatformProxyProvider.h>
#include <JXMPP/Parser/PlatformXMLParserFactory.h>
#include <JXMPP/TLS/PlatformTLSFactories.h>

#ifdef USE_UNBOUND
#include <JXMPP/Network/UnboundDomainNameResolver.h>
#else
#include <JXMPP/Network/PlatformDomainNameResolver.h>
#endif

namespace JXMPP {

BoostNetworkFactories::BoostNetworkFactories(EventLoop* eventLoop, std::shared_ptr<boost::asio::io_service> ioService) : ioServiceThread(ioService), eventLoop(eventLoop) {
    timerFactory = new BoostTimerFactory(ioServiceThread.getIOService(), eventLoop);
    connectionFactory = new BoostConnectionFactory(ioServiceThread.getIOService(), eventLoop);
    connectionServerFactory = new BoostConnectionServerFactory(ioServiceThread.getIOService(), eventLoop);
#ifdef JXMPP_EXPERIMENTAL_FT
    natTraverser = new PlatformNATTraversalWorker(eventLoop);
#else
    natTraverser = new NullNATTraverser(eventLoop);
#endif
    networkEnvironment = new PlatformNetworkEnvironment();
    xmlParserFactory = new PlatformXMLParserFactory();
    tlsFactories = new PlatformTLSFactories();
    proxyProvider = new PlatformProxyProvider();
    idnConverter = PlatformIDNConverter::create();
#ifdef USE_UNBOUND
    // TODO: What to do about idnConverter.
    domainNameResolver = new UnboundDomainNameResolver(idnConverter, ioServiceThread.getIOService(), eventLoop);
#else
    domainNameResolver = new PlatformDomainNameResolver(idnConverter, eventLoop);
#endif
    cryptoProvider = PlatformCryptoProvider::create();
}

BoostNetworkFactories::~BoostNetworkFactories() {
    delete cryptoProvider;
    delete domainNameResolver;
    delete idnConverter;
    delete proxyProvider;
    delete tlsFactories;
    delete xmlParserFactory;
    delete networkEnvironment;
    delete natTraverser;
    delete connectionServerFactory;
    delete connectionFactory;
    delete timerFactory;
}

TLSContextFactory* BoostNetworkFactories::getTLSContextFactory() const {
    return tlsFactories->getTLSContextFactory();
}

}
