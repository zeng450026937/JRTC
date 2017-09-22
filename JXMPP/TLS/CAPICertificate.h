#ifndef JXMPP_CAPICERTIFICATE_H
#define JXMPP_CAPICERTIFICATE_H

#include <JXMPP/Base/API.h>
#include <boost/signals2.hpp>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/TLS/CertificateWithKey.h>
#include <JXMPP/Network/Timer.h>

#define SECURITY_WIN32
#include <Windows.h>
#include <WinCrypt.h>
#include <Winscard.h>

#define SMARTCARD_EJECTION_CHECK_FREQUENCY_MILLISECONDS    1000

namespace JXMPP {
    class TimerFactory;

    class JXMPP_API CAPICertificate : public JXMPP::CertificateWithKey {
        public:
            CAPICertificate(const std::string& capiUri, TimerFactory* timerFactory);

            virtual ~CAPICertificate();

            virtual bool isNull() const;

            const std::string& getCertStoreName() const;

            const std::string& getCertName() const;

            const std::string& getSmartCardReaderName() const;

        public:
            boost::signals2::signal<void ()> onCertificateCardRemoved;

        private:
            void setUri (const std::string& capiUri);

            void handleSmartCardTimerTick();

            bool checkIfSmartCardPresent();

        private:
            bool valid_;
            std::string uri_;

            HCERTSTORE certStoreHandle_;
            SCARDCONTEXT  scardContext_;
            SCARDHANDLE   cardHandle_;

            /* Parsed components of the uri_ */
            std::string certStore_;
            std::string certName_;
            std::string smartCardReaderName_;
            std::shared_ptr<Timer> smartCardTimer_;
            TimerFactory* timerFactory_;

            bool lastPollingResult_;
    };

PCCERT_CONTEXT findCertificateInStore (HCERTSTORE certStoreHandle, const std::string &certName);

}

#endif // JXMPP_CAPICERTIFICATE_H
