#ifndef JXMPP_API_H
#define JXMPP_API_H

#include <JXMPP/Base/Platform.h>
#include <boost/config.hpp>

#ifdef JXMPP_STATIC
# define JXMPP_API
#else
# ifdef JXMPP_PLATFORM_WINDOWS
#  ifdef JXMPP_EXPORT
#   define JXMPP_API __declspec(dllexport)
#  else
#   define JXMPP_API __declspec(dllimport)
#  endif
# elif __GNUC__ >= 4
#  define JXMPP_API __attribute__((visibility("default")))
# else
#  define JXMPP_API
# endif
#endif

#ifdef BOOST_NO_DEFAULTED_FUNCTIONS
#  define JXMPP_DEFAULT_COPY_CONSTRUCTOR(cls)
#  define JXMPP_DEFAULT_COPY_ASSIGMNENT_OPERATOR(cls)
#else
#  define JXMPP_DEFAULT_COPY_CONSTRUCTOR(cls) \
        cls(const cls&) = default;
#  define JXMPP_DEFAULT_COPY_ASSIGMNENT_OPERATOR(cls) \
        cls& operator=(const cls&) = default;
#endif

#ifdef BOOST_NO_NOEXCEPT
#define JXMPP_NOEXCEPT throw()
#else
#define JXMPP_NOEXCEPT noexcept
#endif

#endif // JXMPP_API_H
