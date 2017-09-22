#ifndef JXMPP_BONJOURREGISTERQUERY_H
#define JXMPP_BONJOURREGISTERQUERY_H

#include <mutex>

#include <boost/numeric/conversion/cast.hpp>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/EventLoop/EventLoop.h>
#include <JXMPP/LinkLocal/DNSSD/Bonjour/BonjourQuery.h>
#include <JXMPP/LinkLocal/DNSSD/DNSSDRegisterQuery.h>

namespace JXMPP {
    class BonjourQuerier;

    class BonjourRegisterQuery : public DNSSDRegisterQuery, public BonjourQuery {
        public:
            BonjourRegisterQuery(const std::string& name, int port, const ByteArray& txtRecord, std::shared_ptr<BonjourQuerier> querier, EventLoop* eventLoop) : BonjourQuery(querier, eventLoop) {
                DNSServiceErrorType result = DNSServiceRegister(
                        &sdRef, 0, 0, name.c_str(), "_presence._tcp", nullptr, nullptr, boost::numeric_cast<unsigned short>(port),
                        boost::numeric_cast<unsigned short>(txtRecord.size()), vecptr(txtRecord),
                        &BonjourRegisterQuery::handleServiceRegisteredStatic, this);
                if (result != kDNSServiceErr_NoError) {
                    sdRef = nullptr;
                }
            }

            void registerService() {
                if (sdRef) {
                    run();
                }
                else {
                    eventLoop->postEvent(boost::bind(boost::ref(onRegisterFinished), boost::optional<DNSSDServiceID>()), shared_from_this());
                }
            }

            void unregisterService() {
                finish();
            }

            void updateServiceInfo(const ByteArray& txtRecord) {
                std::lock_guard<std::mutex> lock(sdRefMutex);
                DNSServiceUpdateRecord(sdRef, nullptr, 0, boost::numeric_cast<unsigned short>(txtRecord.size()), vecptr(txtRecord), 0);
            }

        private:
            static void handleServiceRegisteredStatic(DNSServiceRef, DNSServiceFlags, DNSServiceErrorType errorCode, const char *name, const char *regtype, const char *domain, void *context) {
                static_cast<BonjourRegisterQuery*>(context)->handleServiceRegistered(errorCode, name, regtype, domain);
            }

            void handleServiceRegistered(DNSServiceErrorType errorCode, const char *name, const char *regtype, const char *domain) {
                if (errorCode != kDNSServiceErr_NoError) {
                    eventLoop->postEvent(boost::bind(boost::ref(onRegisterFinished), boost::optional<DNSSDServiceID>()), shared_from_this());
                }
                else {
                    eventLoop->postEvent(boost::bind(boost::ref(onRegisterFinished), boost::optional<DNSSDServiceID>(DNSSDServiceID(name, domain, regtype, 0))), shared_from_this());
                }
            }
    };
}

#endif // JXMPP_BONJOURREGISTERQUERY_H
