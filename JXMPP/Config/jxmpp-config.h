#ifndef JXMPP_SWIFTEN-CONFIG_H
#define JXMPP_SWIFTEN-CONFIG_H

static const char* CPPFLAGS[] = {
	"/I#\\3rdParty\\Boost\\src",
	"/D_ITERATOR_DEBUG_LEVEL=0",
	"/DJXMPP_EXPERIMENTAL_FT",
	"/D_WIN32_WINNT=0x0600",
	"/DNTDDI_VERSION=0x06000000",
	"/D_ITERATOR_DEBUG_LEVEL=0",
	"/DJXMPP_EXPERIMENTAL_FT",
	"/DJXMPP_STATIC",
	"/DBOOST_ALL_NO_LIB",
	"/DBOOST_SYSTEM_NO_DEPRECATED",
	"/D_WIN32_WINNT=0x0600",
	"/D_ITERATOR_DEBUG_LEVEL=0",
	"/DJXMPP_EXPERIMENTAL_FT",
	"/I#",
	"/I#",
	"/I#",
	0
};
static const char* LIBFLAGS[] = {
	"/LIBPATH:#\\Swiften",
	"/LIBPATH:#\\3rdParty\\Boost",
	"user32.lib",
	"crypt32.lib",
	"dnsapi.lib",
	"iphlpapi.lib",
	"ws2_32.lib",
	"wsock32.lib",
	"Advapi32.lib",
	"ntdsapi.lib",
	"secur32.lib",
	"Swiften.lib",
	"Swiften_Boost.lib",
	"user32.lib",
	"crypt32.lib",
	"dnsapi.lib",
	"iphlpapi.lib",
	"ws2_32.lib",
	"wsock32.lib",
	"Advapi32.lib",
	"ntdsapi.lib",
	"secur32.lib",
	"Winscard.lib",
	"",
	"",
	"",
	0
};

#endif // JXMPP_SWIFTEN-CONFIG_H
