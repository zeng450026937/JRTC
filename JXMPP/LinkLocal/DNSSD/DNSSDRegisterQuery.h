#ifndef JXMPP_DNSSDREGISTERQUERY_H
#define JXMPP_DNSSDREGISTERQUERY_H

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDServiceID.h>

namespace JXMPP {
    class DNSSDRegisterQuery {
        public:
            virtual ~DNSSDRegisterQuery();

            virtual void registerService() = 0;
            virtual void unregisterService() = 0;
            virtual void updateServiceInfo(const ByteArray& info) = 0;

            boost::signals2::signal<void (boost::optional<DNSSDServiceID>)> onRegisterFinished;
    };
}

#endif // JXMPP_DNSSDREGISTERQUERY_H
