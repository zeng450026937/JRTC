#ifndef JXMPP_S5BPROXYREQUEST_H
#define JXMPP_S5BPROXYREQUEST_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Network/HostAddressPort.h>

namespace JXMPP {

class JXMPP_API S5BProxyRequest : public Payload {
public:
    typedef std::shared_ptr<S5BProxyRequest> ref;

public:
    struct StreamHost {
        std::string host;
        int port;
        JID jid;
    };

public:
    const boost::optional<StreamHost>& getStreamHost() const {
        return streamHost;
    }

    void setStreamHost(const StreamHost& streamHost) {
        this->streamHost = boost::optional<StreamHost>(streamHost);
    }

    const std::string& getSID() const {
        return sid;
    }

    void setSID(const std::string& sid) {
        this->sid = sid;
    }

    const boost::optional<JID>& getActivate() const {
        return activate;
    }

    void setActivate(const JID& activate) {
        this->activate = activate;
    }

private:
    boost::optional<StreamHost> streamHost;

    std::string sid;
    boost::optional<JID> activate;
};

}

#endif // JXMPP_S5BPROXYREQUEST_H
