#ifndef JXMPP_CLIENTOPTIONS_H
#define JXMPP_CLIENTOPTIONS_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeString.h>
#include <JXMPP/Base/URL.h>
#include <JXMPP/TLS/TLSOptions.h>

namespace JXMPP {
    class HTTPTrafficFilter;

    struct JXMPP_API ClientOptions {
        enum UseTLS {
            NeverUseTLS,
            UseTLSWhenAvailable,
            RequireTLS
        };

        enum ProxyType {
            NoProxy,
            SystemConfiguredProxy,
            SOCKS5Proxy,
            HTTPConnectProxy
        };

        ClientOptions() {
        }

        /**
         * Whether ZLib stream compression should be used when available.
         *
         * Default: true
         */
        bool useStreamCompression = true;

        /**
         * Sets whether TLS encryption should be used.
         *
         * Default: UseTLSWhenAvailable
         */
        UseTLS useTLS = UseTLSWhenAvailable;

        /**
         * Sets whether plaintext authentication is
         * allowed over non-TLS-encrypted connections.
         *
         * Default: false
         */
        bool allowPLAINWithoutTLS = false;

        /**
         * Use XEP-196 stream resumption when available.
         *
         * Default: false
         */
        bool useStreamResumption = false;

        /**
         * Forget the password once it's used.
         * This makes the Client useless after the first login attempt.
         *
         * FIXME: This is a temporary workaround.
         *
         * Default: false
         */
        bool forgetPassword = false;

        /**
         * Use XEP-0198 acks in the stream when available.
         * Default: true
         */
        bool useAcks = true;

        /**
         * Use Single Sign On.
         * Default: false
         */
        bool singleSignOn = false;

        /**
         * The hostname to connect to.
         * Leave this empty for standard XMPP connection, based on the JID domain.
         */
        std::string manualHostname = "";

        /**
         * The port to connect to.
         * Leave this to -1 to use the port discovered by SRV lookups, and 5222 as a
         * fallback.
         */
        int manualPort = -1;

        /**
         * The type of proxy to use for connecting to the XMPP
         * server.
         */
        ProxyType proxyType = SystemConfiguredProxy;

        /**
         * Override the system-configured proxy hostname.
         */
        std::string manualProxyHostname = "";

        /**
         * Override the system-configured proxy port.
         */
        int manualProxyPort = -1;

        /**
         * If non-empty, use BOSH instead of direct TCP, with the given URL.
         * Default: empty (no BOSH)
         */
        URL boshURL = URL();

        /**
         * If non-empty, BOSH connections will try to connect over this HTTP CONNECT
         * proxy instead of directly.
         * Default: empty (no proxy)
         */
        URL boshHTTPConnectProxyURL = URL();

        /**
         * If this and matching Password are non-empty, BOSH connections over
         * HTTP CONNECT proxies will use these credentials for proxy access.
         * Default: empty (no authentication needed by the proxy)
         */
        SafeString boshHTTPConnectProxyAuthID = SafeString("");
        SafeString boshHTTPConnectProxyAuthPassword = SafeString("");

        /**
         * This can be initialized with a custom HTTPTrafficFilter, which allows HTTP CONNECT
         * proxy initialization to be customized.
         */
        std::shared_ptr<HTTPTrafficFilter> httpTrafficFilter;

        /**
         * Options passed to the TLS stack
         */
        TLSOptions tlsOptions;

        /**
         * Session shutdown timeout in milliseconds. This is the maximum time Swiften
         * waits from a session close to the socket close.
         */
        int sessionShutdownTimeoutInMilliseconds = 10000;
    };
}

#endif // JXMPP_CLIENTOPTIONS_H
