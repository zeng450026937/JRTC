#ifndef JXMPP_PLATFORM_H
#define JXMPP_PLATFORM_H

// Base platforms
#if defined(linux) || defined(__linux) || defined(__linux__)
#define JXMPP_PLATFORM_LINUX
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
#define JXMPP_PLATFORM_BSD
#elif defined(sun) || defined(__sun)
#define JXMPP_PLATFORM_SOLARIS
#elif defined(__sgi)
#define JXMPP_PLATFORM_SGI
#elif defined(__hpux)
#define JXMPP_PLATFORM_HPUX
#elif defined(__CYGWIN__)
#define JXMPP_PLATFORM_CYGWIN
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define JXMPP_PLATFORM_WIN32
#elif defined(__BEOS__)
#define JXMPP_PLATFORM_BEOS
#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#define JXMPP_PLATFORM_MACOSX
#include <TargetConditionals.h>
#  if TARGET_OS_IPHONE == 1
#  define JXMPP_PLATFORM_IPHONE
#  endif
#elif defined(__IBMCPP__) || defined(_AIX)
#define JXMPP_PLATFORM_AIX
#elif defined(__amigaos__)
#define JXMPP_PLATFORM_AMIGAOS
#elif defined(__QNXNTO__)
#define JXMPP_PLATFORM_QNX
#endif

// Derived platforms
#if defined(JXMPP_PLATFORM_CYGWIN) || defined(JXMPP_PLATFORM_WIN32)
#define JXMPP_PLATFORM_WINDOWS
#endif

// Endianness
#include <boost/detail/endian.hpp>
#if defined(BOOST_LITTLE_ENDIAN)
#define JXMPP_LITTLE_ENDIAN
#elif defined(BOOST_BIG_ENDIAN)
#define JXMPP_BIG_ENDIAN
#endif

#endif // JXMPP_PLATFORM_H
