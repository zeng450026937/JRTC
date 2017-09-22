#ifndef JXMPP_PLATFORMNETWORKENVIRONMENT_H
#define JXMPP_PLATFORMNETWORKENVIRONMENT_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/Platform.h>

#if defined(JXMPP_PLATFORM_MACOSX)
#include <JXMPP/Network/UnixNetworkEnvironment.h>
namespace JXMPP {
    typedef UnixNetworkEnvironment PlatformNetworkEnvironment;
}
#elif defined(JXMPP_PLATFORM_WIN32)
#include <JXMPP/Network/WindowsNetworkEnvironment.h>
namespace JXMPP {
    typedef WindowsNetworkEnvironment PlatformNetworkEnvironment;
}
#elif defined(JXMPP_PLATFORM_SOLARIS)
#include <JXMPP/Network/SolarisNetworkEnvironment.h>
namespace JXMPP {
    typedef SolarisNetworkEnvironment PlatformNetworkEnvironment;
}

#else
#include <JXMPP/Network/UnixNetworkEnvironment.h>
namespace JXMPP {
    typedef UnixNetworkEnvironment PlatformNetworkEnvironment;
}
#endif

#endif // JXMPP_PLATFORMNETWORKENVIRONMENT_H
