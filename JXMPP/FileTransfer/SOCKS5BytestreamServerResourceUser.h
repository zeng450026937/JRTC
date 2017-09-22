#ifndef JXMPP_SOCKS5BYTESTREAMSERVERRESOURCEUSER_H
#define JXMPP_SOCKS5BYTESTREAMSERVERRESOURCEUSER_H

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {

class SOCKS5BytestreamServerManager;

class JXMPP_API SOCKS5BytestreamServerResourceUser {
    public:
        SOCKS5BytestreamServerResourceUser(SOCKS5BytestreamServerManager* s5bServerManager);
        ~SOCKS5BytestreamServerResourceUser();

        bool isInitialized() const;

        boost::signals2::signal<void (bool /* success */)> onSuccessfulInitialized;

    private:
        void handleServerManagerInitialized(bool successfulInitialize);

    private:
        SOCKS5BytestreamServerManager* s5bServerManager_;
        boost::signals2::scoped_connection onInitializedConnection_;
};

}

#endif // JXMPP_SOCKS5BYTESTREAMSERVERRESOURCEUSER_H
