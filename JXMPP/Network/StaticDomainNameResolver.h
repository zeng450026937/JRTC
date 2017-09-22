#ifndef JXMPP_STATICDOMAINNAMERESOLVER_H
#define JXMPP_STATICDOMAINNAMERESOLVER_H

#include <map>
#include <memory>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/Network/DomainNameAddressQuery.h>
#include <JXMPP/Network/DomainNameResolver.h>
#include <JXMPP/Network/DomainNameServiceQuery.h>
#include <JXMPP/Network/HostAddress.h>
#include <JXMPP/Network/HostAddressPort.h>

namespace JXMPP {
    class JXMPP_API StaticDomainNameResolver : public DomainNameResolver {
        public:
            typedef std::map<std::string, std::vector<HostAddress> > AddressesMap;
            typedef std::vector< std::pair<std::string, DomainNameServiceQuery::Result> > ServicesCollection;

        public:
            StaticDomainNameResolver(EventLoop* eventLoop);
            virtual ~StaticDomainNameResolver();

            void addAddress(const std::string& domain, const HostAddress& address);
            void addService(const std::string& service, const DomainNameServiceQuery::Result& result);
            void addXMPPClientService(const std::string& domain, const HostAddressPort&);
            void addXMPPClientService(const std::string& domain, const std::string& host, int port);

            const AddressesMap& getAddresses() const {
                return addresses;
            }

            const ServicesCollection& getServices() const {
                return services;
            }

            bool getIsResponsive() const {
                return isResponsive;
            }

            void setIsResponsive(bool b) {
                isResponsive = b;
            }

            virtual std::shared_ptr<DomainNameServiceQuery> createServiceQuery(const std::string& serviceLookupPrefix, const std::string& domain);
            virtual std::shared_ptr<DomainNameAddressQuery> createAddressQuery(const std::string& name);
        private:
            EventLoop* eventLoop;
            bool isResponsive;
            AddressesMap addresses;
            ServicesCollection services;
            std::shared_ptr<EventOwner> owner;
    };
}

#endif // JXMPP_STATICDOMAINNAMERESOLVER_H
