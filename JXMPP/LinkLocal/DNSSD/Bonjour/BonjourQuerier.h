#ifndef JXMPP_BONJOURQUERIER_H
#define JXMPP_BONJOURQUERIER_H

#include <list>
#include <memory>
#include <mutex>
#include <thread>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/LinkLocal/DNSSD/Bonjour/BonjourQuery.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDQuerier.h>

namespace JXMPP {
    class BonjourQuerier :
            public DNSSDQuerier,
            public std::enable_shared_from_this<BonjourQuerier> {
        public:
            BonjourQuerier(EventLoop* eventLoop);
            ~BonjourQuerier();

            std::shared_ptr<DNSSDBrowseQuery> createBrowseQuery();
            std::shared_ptr<DNSSDRegisterQuery> createRegisterQuery(
                    const std::string& name, int port, const ByteArray& info);
            std::shared_ptr<DNSSDResolveServiceQuery> createResolveServiceQuery(
                    const DNSSDServiceID&);
            std::shared_ptr<DNSSDResolveHostnameQuery> createResolveHostnameQuery(
                    const std::string& hostname, int interfaceIndex);

            void start();
            void stop();

        private:
            friend class BonjourQuery;

            void addRunningQuery(std::shared_ptr<BonjourQuery>);
            void removeRunningQuery(std::shared_ptr<BonjourQuery>);
            void interruptSelect();
            void run();

        private:
            EventLoop* eventLoop;
            bool stopRequested;
            std::thread* thread;
            std::mutex runningQueriesMutex;
            std::list< std::shared_ptr<BonjourQuery> > runningQueries;
            int interruptSelectReadSocket;
            int interruptSelectWriteSocket;
            std::condition_variable runningQueriesAvailableEvent;
    };
}

#endif // JXMPP_BONJOURQUERIER_H
