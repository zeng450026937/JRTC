#ifndef JXMPP_NATTRAVERSALFORWARDPORTREQUEST_H
#define JXMPP_NATTRAVERSALFORWARDPORTREQUEST_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Network/NATPortMapping.h>

namespace JXMPP {
    class JXMPP_API NATTraversalForwardPortRequest {
        public:
            virtual ~NATTraversalForwardPortRequest();

            virtual void start() = 0;
            virtual void stop() = 0;

            boost::signals2::signal<void (boost::optional<NATPortMapping>)> onResult;
    };
}

#endif // JXMPP_NATTRAVERSALFORWARDPORTREQUEST_H
