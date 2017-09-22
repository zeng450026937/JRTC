#ifndef JXMPP_LINKLOCALSERVICEBROWSER_H
#define JXMPP_LINKLOCALSERVICEBROWSER_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDQuerier.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDRegisterQuery.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDResolveServiceQuery.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDServiceID.h>
#include <JXMPP/LinkLocal/LinkLocalService.h>
#include <JXMPP/LinkLocal/LinkLocalServiceInfo.h>

namespace JXMPP {
    class JXMPP_API LinkLocalServiceBrowser {
        public:
            LinkLocalServiceBrowser(std::shared_ptr<DNSSDQuerier> querier);
            ~LinkLocalServiceBrowser();

            void start();
            void stop();
            bool isRunning() const;
            bool hasError() const;

            void registerService(
                    const std::string& name,
                    int port,
                    const LinkLocalServiceInfo& info = LinkLocalServiceInfo());
            void updateService(
                    const LinkLocalServiceInfo& info = LinkLocalServiceInfo());
            void unregisterService();
            bool isRegistered() const;

            std::vector<LinkLocalService> getServices() const;

            // FIXME: Ugly that we need this
            std::shared_ptr<DNSSDQuerier> getQuerier() const {
                return querier;
            }

            boost::signals2::signal<void (const LinkLocalService&)> onServiceAdded;
            boost::signals2::signal<void (const LinkLocalService&)> onServiceChanged;
            boost::signals2::signal<void (const LinkLocalService&)> onServiceRemoved;
            boost::signals2::signal<void (const DNSSDServiceID&)> onServiceRegistered;
            boost::signals2::signal<void (bool)> onStopped;

        private:
            void handleServiceAdded(const DNSSDServiceID&);
            void handleServiceRemoved(const DNSSDServiceID&);
            void handleServiceResolved(const DNSSDServiceID& service, const boost::optional<DNSSDResolveServiceQuery::Result>& result);
            void handleRegisterFinished(const boost::optional<DNSSDServiceID>&);
            void handleBrowseError();

        private:
            std::shared_ptr<DNSSDQuerier> querier;
            boost::optional<DNSSDServiceID> selfService;
            std::shared_ptr<DNSSDBrowseQuery> browseQuery;
            std::shared_ptr<DNSSDRegisterQuery> registerQuery;
            typedef std::map<DNSSDServiceID, std::shared_ptr<DNSSDResolveServiceQuery> > ResolveQueryMap;
            ResolveQueryMap resolveQueries;
            typedef std::map<DNSSDServiceID, DNSSDResolveServiceQuery::Result> ServiceMap;
            ServiceMap services;
            bool haveError;
    };
}

#endif // JXMPP_LINKLOCALSERVICEBROWSER_H
