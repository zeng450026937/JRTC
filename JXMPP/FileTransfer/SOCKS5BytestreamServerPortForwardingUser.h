#ifndef JXMPP_SOCKS5BYTESTREAMSERVERPORTFORWARDINGUSER_H
#define JXMPP_SOCKS5BYTESTREAMSERVERPORTFORWARDINGUSER_H

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {

class SOCKS5BytestreamServerManager;

class JXMPP_API SOCKS5BytestreamServerPortForwardingUser {
    public:
        SOCKS5BytestreamServerPortForwardingUser(SOCKS5BytestreamServerManager* s5bServerManager);
        ~SOCKS5BytestreamServerPortForwardingUser();

        bool isForwardingSetup() const;

        boost::signals2::signal<void (bool /* success */)> onSetup;

    private:
        void handleServerManagerPortForwardingSetup(bool successful);

    private:
        SOCKS5BytestreamServerManager* s5bServerManager_;
        boost::signals2::scoped_connection onPortForwardingSetupConnection_;
};

}

#endif // JXMPP_SOCKS5BYTESTREAMSERVERPORTFORWARDINGUSER_H
