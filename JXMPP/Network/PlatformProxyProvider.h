#ifndef JXMPP_PLATFORMPROXYPROVIDER_H
#define JXMPP_PLATFORMPROXYPROVIDER_H

/*
 * Copyright (c) 2010-2011 Thilo Cestonaro
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/Platform.h>

#if defined(JXMPP_PLATFORM_MACOSX)
#include <JXMPP/Network/MacOSXProxyProvider.h>
namespace JXMPP {
    typedef MacOSXProxyProvider PlatformProxyProvider;
}
#elif defined(JXMPP_PLATFORM_WIN32)
#include <JXMPP/Network/WindowsProxyProvider.h>
namespace JXMPP {
    typedef WindowsProxyProvider PlatformProxyProvider;
}
#else
#include <JXMPP/Network/UnixProxyProvider.h>
namespace JXMPP {
    typedef UnixProxyProvider PlatformProxyProvider;
}
#endif

#endif // JXMPP_PLATFORMPROXYPROVIDER_H
