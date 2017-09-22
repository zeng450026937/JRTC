#ifndef JXMPP_NATTRAVERSALGETPUBLICIPREQUEST_H
#define JXMPP_NATTRAVERSALGETPUBLICIPREQUEST_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/HostAddress.h>

namespace JXMPP {
    class JXMPP_API NATTraversalGetPublicIPRequest {
        public:
            virtual ~NATTraversalGetPublicIPRequest();

            virtual void start() = 0;
            virtual void stop() = 0;

            boost::signals2::signal<void (boost::optional<HostAddress>)> onResult;
    };
}

#endif // JXMPP_NATTRAVERSALGETPUBLICIPREQUEST_H
