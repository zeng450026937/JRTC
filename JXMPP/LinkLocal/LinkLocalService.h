#ifndef JXMPP_LINKLOCALSERVICE_H
#define JXMPP_LINKLOCALSERVICE_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDResolveServiceQuery.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDServiceID.h>
#include <JXMPP/LinkLocal/LinkLocalServiceInfo.h>

namespace JXMPP {
    class JXMPP_API LinkLocalService {
        public:
            LinkLocalService(
                    const DNSSDServiceID& id,
                    const DNSSDResolveServiceQuery::Result& info) :
                        id(id),
                        info(info) {}

            const DNSSDServiceID& getID() const {
                return id;
            }

            const std::string& getName() const {
                return id.getName();
            }

            int getPort() const {
                return info.port;
            }

            const std::string& getHostname() const {
                return info.host;
            }

            LinkLocalServiceInfo getInfo() const {
                return LinkLocalServiceInfo::createFromTXTRecord(info.info);
            }

            std::string getDescription() const;

            JID getJID() const;

        private:
            DNSSDServiceID id;
            DNSSDResolveServiceQuery::Result info;
    };
}

#endif // JXMPP_LINKLOCALSERVICE_H
