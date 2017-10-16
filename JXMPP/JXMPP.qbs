import qbs

Project {
    property bool withExamples: true

    SubProject {
        filePath: "Examples/Examples.qbs"
        Properties {
            condition: parent.withExamples
        }
    }

    Product {
        name: "JXMPP"
        //type: "staticlibrary"
        type: "dynamiclibrary"
        version: "1.0"

        Depends {
            name: "cpp"
        }
        Depends {
            condition: project.BOOST_BUNDLED
            name: "Boost"
            cpp.link: true
            cpp.linkWholeArchive: false
        }
        Depends {
            condition: project.EXPAT_BUNDLED
            name: "Expat"
            cpp.link: true
            cpp.linkWholeArchive: false
        }
        Depends {
            condition: project.ICU_BUNDLED
            name: "ICU"
            cpp.link: true
            cpp.linkWholeArchive: false
        }
        Depends {
            condition: project.LIBIDN_BUNDLED
            name: "LibIDN"
            cpp.link: true
            cpp.linkWholeArchive: false
        }
        Depends {
            condition: project.LIBMINIUPNPC_BUNDLED
            name: "LibMiniUPnPc"
            cpp.link: true
            cpp.linkWholeArchive: false
        }
        Depends {
            condition: project.LIBNATPMP_BUNDLED
            name: "LibNATPMP"
            cpp.link: true
            cpp.linkWholeArchive: false
        }
        Depends {
            condition: project.OPENSSL_BUNDLED
            name: "OpenSSL"
            cpp.link: true
            cpp.linkWholeArchive: false
        }    
        Depends {
            condition: project.SQLITE_BUNDLED
            name: "SQLite"
            cpp.link: true
            cpp.linkWholeArchive: false
        }
        Depends {
            condition: project.ZLIB_BUNDLED
            name: "ZLib"
            cpp.link: true
            cpp.linkWholeArchive: false
        }

        cpp.defines: {
            // 0x0600 = _WIN32_WINNT_VISTA, 0x06000000 = NTDDI_VISTA
            var def = ["JXMPP_EXPORT", "BOOST_ALL_NO_LIB", "NEED_IDN", "_WIN32_WINNT=0x0600", "NTDDI_VERSION=0x06000000"]

            if (project.BOOST_BUNDLED)
                def.push("HAVE_BOOST")
            if (project.EXPAT_BUNDLED)
                def.push("HAVE_EXPAT")
            if (project.ICU_BUNDLED)
                def.push("HAVE_ICU")
            if (project.LDNS_BUNDLED)
                def.push("HAVE_LDNS")
            if (project.LIBIDN_BUNDLED)
                def.push("HAVE_LIBIDN")
            if (project.LIBMINIUPNPC_BUNDLED)
                def.push("HAVE_LIBMINIUPNPC")
            if (project.LIBNATPMP_BUNDLED)
                def.push("HAVE_LIBNATPMP")
            if (project.OPENSSL_BUNDLED)
                def.push("HAVE_OPENSSL")
            if (project.SQLITE_BUNDLED)
                def.push("HAVE_SQLITE")
            if (project.UNBOUND_BUNDLED)
                def.push("USE_UNBOUND")
            if (project.ZLIB_BUNDLED)
                def.push("HAVE_ZLIB")
            
            var experimental = ["SWIFT_EXPERIMENTAL_FT", "SWIFT_EXPERIMENTAL_HISTORY", "SWIFT_EXPERIMENTAL_WB"]

            return def.concat(experimental)
        }
        cpp.includePaths: ["../"]

        property stringList librarys: ["user32", "crypt32", "dnsapi", "iphlpapi", "ws2_32", "wsock32", "Advapi32", "ntdsapi"]

        Properties {
            condition: product.type == "staticlibrary"
            cpp.defines: outer.concat(["JXMPP_STATIC"])
        }
        Properties {
            condition: qbs.targetOS.contains("windows")
            cpp.defines: outer.concat(["HAVE_SCHANNEL"])
            cpp.cxxFlags: ["/EHsc", "/nologo", "/Zm256", "/bigobj"]
            cpp.linkerFlags: ["/INCREMENTAL:no", "/NOLOGO"]
            cpp.staticLibraries: outer.concat(librarys)
            cpp.dynamicLibraries: outer.concat(librarys)
        }
        Properties {
            condition: qbs.targetOS.contains("darwin")
            cpp.defines: outer.concat(["HAVE_SECURETRANSPORT"])
        }

        Group {
            name: "AdHoc"
            prefix: "AdHoc/"
            files: ["OutgoingAdHocCommandSession.cpp"]
        }
        Group {
            name: "Avatars"
            prefix: "Avatars/"
            files: [
                "VCardUpdateAvatarManager.cpp",
                "VCardAvatarManager.cpp",
                "OfflineAvatarManager.cpp",
                "AvatarManager.cpp",
                "AvatarManagerImpl.cpp",
                "AvatarStorage.cpp",
                "AvatarProvider.cpp",
                "CombinedAvatarProvider.cpp"
            ]
        }
        Group {
            name: "Base"
            prefix: "Base/"
            files: [
                "ByteArray.cpp",
                "DateTime.cpp",
                "Debug.cpp",
                "Error.cpp",
                "FileSize.cpp",
                "IDGenerator.cpp",
                "Log.cpp",
                "LogSerializers.cpp",
                "Path.cpp",
                "Paths.cpp",
                "RandomGenerator.cpp",
                "Regex.cpp",
                "SafeAllocator.cpp",
                "SafeByteArray.cpp",
                "SimpleIDGenerator.cpp",
                "StdRandomGenerator.cpp",
                "String.cpp",
                "URL.cpp",
                "sleep.cpp"
            ]
        }
        Group {
            name: "Chat"
            prefix: "Chat/"
            files: [
                "ChatStateTracker.cpp",
                "ChatStateNotifier.cpp"
            ]
        }
        Group {
            name: "Client"
            prefix: "Client/"
            files: [
                "ClientSessionStanzaChannel.cpp",
                "CoreClient.cpp",
                "Client.cpp",
                "ClientXMLTracer.cpp",
                "ClientSession.cpp",
                "BlockList.cpp",
                "BlockListImpl.cpp",
                "ClientBlockListManager.cpp",
                "MemoryStorages.cpp",
                "NickResolver.cpp",
                "NickManager.cpp",
                "NickManagerImpl.cpp",
                "Storages.cpp",
                "XMLBeautifier.cpp"
            ]
        }
        Group {
            name: "Component"
            prefix: "Component/"
            files: [
                "ComponentHandshakeGenerator.cpp",
                "ComponentConnector.cpp",
                "ComponentSession.cpp",
                "ComponentSessionStanzaChannel.cpp",
                "CoreComponent.cpp",
                "Component.cpp",
                "ComponentXMLTracer.cpp"
            ]
        }
        Group {
            name: "Compress"
            prefix: "Compress/"
            files: [
                "ZLibCodecompressor.cpp",
                "ZLibDecompressor.cpp",
                "ZLibCompressor.cpp"
            ]
        }
        Group {
            name: "Crypto"
            prefix: "Crypto/"
            files: [
                "CryptoProvider.cpp",
                "Hash.cpp",
                "PlatformCryptoProvider.cpp"
            ]
            Group {
                condition: qbs.targetOS.contains("windows")
                prefix: parent.prefix
                files: ["WindowsCryptoProvider.cpp"]
            }
            Group {
                condition: qbs.targetOS.contains("darwin")
                prefix: parent.prefix
                files: ["CommonCryptoCryptoProvider.cpp"]
            }
            Group {
                condition: cpp.defines.contains("HAVE_OPENSSL")
                prefix: parent.prefix
                files: ["OpenSSLCryptoProvider.cpp"]
            }
        }
        Group {
            name: "Disco"
            prefix: "Disco/"
            files: [
                "CapsInfoGenerator.cpp",
                "CapsManager.cpp",
                "EntityCapsManager.cpp",
                "EntityCapsProvider.cpp",
                "DummyEntityCapsProvider.cpp",
                "CapsStorage.cpp",
                "ClientDiscoManager.cpp",
                "DiscoInfoResponder.cpp",
                "JIDDiscoInfoResponder.cpp",
                "DiscoServiceWalker.cpp",
                "FeatureOracle.cpp"
            ]
        }
        Group {
            name: "Elements"
            prefix: "Elements/"
            files: [
                "CarbonsEnable.cpp",
                "CarbonsDisable.cpp",
                "CarbonsPrivate.cpp",
                "CarbonsReceived.cpp",
                "CarbonsSent.cpp",
                "DiscoInfo.cpp",
                "Presence.cpp",
                "Form.cpp",
                "FormField.cpp",
                "FormPage.cpp",
                "FormSection.cpp",
                "FormText.cpp",
                "StreamFeatures.cpp",
                "Element.cpp",
                "ToplevelElement.cpp",
                "IQ.cpp",
                "Payload.cpp",
                "PubSubPayload.cpp",
                "PubSubOwnerPayload.cpp",
                "PubSubEventPayload.cpp",
                "RosterItemExchangePayload.cpp",
                "RosterPayload.cpp",
                "SecurityLabel.cpp",
                "Stanza.cpp",
                "StanzaAck.cpp",
                "StatusShow.cpp",
                "StreamManagementEnabled.cpp",
                "StreamResume.cpp",
                "StreamResumed.cpp",
                "UserLocation.cpp",
                "UserTune.cpp",
                "VCard.cpp",
                "MUCOccupant.cpp",
                "ResultSet.cpp",
                "Forwarded.cpp",
                "MAMResult.cpp",
                "MAMQuery.cpp",
                "MAMFin.cpp",
                "Thread.cpp",
                "IsodeIQDelegation.cpp"
            ]
        }
        Group {
            name: "Entity"
            prefix: "Entity/"
            files: [
                "Entity.cpp",
                "PayloadPersister.cpp"
            ]
        }
        Group {
            name: "EventLoop"
            prefix: "EventLoop/"
            files: [
                "BoostASIOEventLoop.cpp",
                "DummyEventLoop.cpp",
                "Event.cpp",
                "EventLoop.cpp",
                "EventOwner.cpp",
                "SimpleEventLoop.cpp",
                "SingleThreadedEventLoop.cpp",
            ]
            Group {
                condition: qbs.targetOS.contains("darwin")
                prefix: parent.prefix
                files: [
                    "Cocoa/CocoaEventLoop.mm",
                    "Cocoa/CocoaEvent.mm"
                ]
            }
        }
        Group {
            name: "FileTransfer"
            prefix: "FileTransfer/"
            files: [
                "ByteArrayReadBytestream.cpp",
                "DefaultFileTransferTransporter.cpp",
                "DefaultFileTransferTransporterFactory.cpp",
                "FailingTransportSession.cpp",
                "FileReadBytestream.cpp",
                "FileTransfer.cpp",
                "FileTransferManager.cpp",
                "FileTransferManagerImpl.cpp",
                "FileTransferOptions.cpp",
                "FileTransferTransporter.cpp",
                "FileTransferTransporterFactory.cpp",
                "FileWriteBytestream.cpp",
                "IBBReceiveSession.cpp",
                "IBBReceiveTransportSession.cpp",
                "IBBSendSession.cpp",
                "IBBSendTransportSession.cpp",
                "IncomingFileTransfer.cpp",
                "IncomingFileTransferManager.cpp",
                "IncomingJingleFileTransfer.cpp",
                "IncrementalBytestreamHashCalculator.cpp",
                "JingleFileTransfer.cpp",
                "LocalJingleTransportCandidateGenerator.cpp",
                "OutgoingFileTransfer.cpp",
                "OutgoingFileTransferManager.cpp",
                "OutgoingJingleFileTransfer.cpp",
                "ReadBytestream.cpp",
                "RemoteJingleTransportCandidateSelector.cpp",
                "SOCKS5BytestreamClientSession.cpp",
                "SOCKS5BytestreamProxiesManager.cpp",
                "SOCKS5BytestreamProxyFinder.cpp",
                "SOCKS5BytestreamRegistry.cpp",
                "SOCKS5BytestreamServer.cpp",
                "SOCKS5BytestreamServerManager.cpp",
                "SOCKS5BytestreamServerPortForwardingUser.cpp",
                "SOCKS5BytestreamServerResourceUser.cpp",
                "SOCKS5BytestreamServerSession.cpp",
                "TransportSession.cpp",
                "WriteBytestream.cpp"
            ]
        }
        Group {
            name: "History"
            prefix: "History/"
            files: ["SQLiteHistoryStorage.cpp"]
        }
        Group {
            name: "IDN"
            prefix: "IDN/"
            files: [
                "IDNConverter.cpp",
                "PlatformIDNConverter.cpp"
            ]
            Group {
                condition: cpp.defines.contains("HAVE_ICU")
                prefix: parent.prefix
                files: ["ICUConverter.cpp"]
            }
            Group {
                condition: cpp.defines.contains("HAVE_LIBIDN")
                prefix: parent.prefix
                files: ["LibIDNConverter.cpp"]
            }
        }
        Group {
            name: "JID"
            prefix: "JID/"
            files: ["JID.cpp"]
        }
        Group {
            name: "Jingle"
            prefix: "Jingle/"
            files: [
                "JingleSession.cpp",
                "JingleSessionListener.cpp",
                "AbstractJingleSessionListener.cpp",
                "JingleSessionImpl.cpp",    
                "IncomingJingleSessionHandler.cpp",
                "JingleSessionManager.cpp", 
                "JingleResponder.cpp",
                "FakeJingleSession.cpp"
            ]
        }
        Group {
            name: "LinkLocal"
            prefix: "LinkLocal/"
            files: [
                "DNSSD/DNSSDBrowseQuery.cpp",
                "DNSSD/DNSSDQuerier.cpp",
                "DNSSD/DNSSDRegisterQuery.cpp",
                "DNSSD/DNSSDResolveHostnameQuery.cpp",
                "DNSSD/DNSSDResolveServiceQuery.cpp",
                "DNSSD/DNSSDServiceID.cpp",
                "DNSSD/Fake/FakeDNSSDQuerier.cpp",
                "DNSSD/Fake/FakeDNSSDQuery.cpp",
                "DNSSD/PlatformDNSSDQuerierFactory.cpp",
                "IncomingLinkLocalSession.cpp",
                "LinkLocalConnector.cpp",
                "LinkLocalService.cpp",
                "LinkLocalServiceBrowser.cpp",
                "LinkLocalServiceInfo.cpp",
                "OutgoingLinkLocalSession.cpp"
            ]
            Group {
                condition: cpp.defines.contains("HAVE_BONJOUR")
                prefix: parent.prefix
                files: [
                    "DNSSD/Bonjour/BonjourQuerier.cpp",
                    "DNSSD/Bonjour/BonjourQuery.cpp"
                ]
            }
            Group {
                condition: cpp.defines.contains("HAVE_AVAHI")
                prefix: parent.prefix
                files: [   
                    "DNSSD/Avahi/AvahiQuerier.cpp",
                    "DNSSD/Avahi/AvahiQuery.cpp",
                    "DNSSD/Avahi/AvahiResolveHostnameQuery.cpp",
                    "DNSSD/Avahi/AvahiResolveServiceQuery.cpp",
                    "DNSSD/Avahi/AvahiRegisterQuery.cpp",
                    "DNSSD/Avahi/AvahiBrowseQuery.cpp"
                ]
            }
        }
        Group {
            name: "MIX"
            prefix: "MIX/"
            files: [
                "MIX.cpp",
                "MIXImpl.cpp"
            ]
        }
        Group {
            name: "MUC"
            prefix: "MUC/"
            files: [
                "MUC.cpp",
                "MUCImpl.cpp",
                "MUCManager.cpp",
                "MUCRegistry.cpp",
                "MUCBookmarkManager.cpp"
            ]
        }
        Group {
            name: "Network"
            prefix: "Network/"
            files: [
                "ProxiedConnection.cpp",
                "HTTPConnectProxiedConnection.cpp",
                "HTTPConnectProxiedConnectionFactory.cpp",
                "SOCKS5ProxiedConnection.cpp",
                "SOCKS5ProxiedConnectionFactory.cpp",
                "BoostConnection.cpp",
                "BoostConnectionFactory.cpp",
                "BoostConnectionServer.cpp",
                "BoostConnectionServerFactory.cpp",
                "BoostIOServiceThread.cpp",
                "BOSHConnection.cpp",
                "BOSHConnectionPool.cpp",
                "CachingDomainNameResolver.cpp",
                "ConnectionFactory.cpp",
                "ConnectionServer.cpp",
                "ConnectionServerFactory.cpp",
                "DummyConnection.cpp",
                "FakeConnection.cpp",
                "ChainedConnector.cpp",
                "Connector.cpp",
                "Connection.cpp",
                "TimerFactory.cpp",
                "DummyTimerFactory.cpp",
                "BoostTimerFactory.cpp",
                "DomainNameResolver.cpp",
                "DomainNameAddressQuery.cpp",
                "DomainNameServiceQuery.cpp",
                "StaticDomainNameResolver.cpp",
                "HostAddress.cpp",
                "HostAddressPort.cpp",
                "HostNameOrAddress.cpp",
                "NetworkFactories.cpp",
                "BoostNetworkFactories.cpp",
                "NetworkEnvironment.cpp",
                "Timer.cpp",
                "TLSConnection.cpp",
                "TLSConnectionFactory.cpp",
                "BoostTimer.cpp",
                "ProxyProvider.cpp",
                "NullProxyProvider.cpp",
                "NATTraverser.cpp",
                "NullNATTraverser.cpp",
                "NATTraversalGetPublicIPRequest.cpp",
                "NATTraversalForwardPortRequest.cpp",
                "NATTraversalRemovePortForwardingRequest.cpp",
                "NATTraversalInterface.cpp",
                "HTTPTrafficFilter.cpp",
                "PlatformNATTraversalWorker.cpp"
            ]
            Group {
                condition: cpp.defines.contains("USE_UNBOUND")
                prefix: parent.prefix
                files: ["UnboundDomainNameResolver.cpp"]
            }
            Group {
                condition: !cpp.defines.contains("USE_UNBOUND")
                prefix: parent.prefix
                files: [
                    "PlatformDomainNameResolver.cpp",
                    "PlatformDomainNameServiceQuery.cpp",
                    "PlatformDomainNameAddressQuery.cpp"
                ]
            }
            Group {
                condition: qbs.targetOS.contains("darwin")
                prefix: parent.prefix
                files: ["MacOSXProxyProvider.cpp","UnixNetworkEnvironment.cpp"]
            }
            Group {
                condition: qbs.targetOS.contains("win32")
                prefix: parent.prefix
                files: ["WindowsProxyProvider.cpp","WindowsNetworkEnvironment.cpp"]
            }
            Group {
                condition: qbs.targetOS.contains("solaris")
                prefix: parent.prefix
                files: ["UnixProxyProvider.cpp","SolarisNetworkEnvironment.cpp","EnvironmentProxyProvider.cpp"]
            }
            Group {
                condition: qbs.targetOS.contains("unix")
                prefix: parent.prefix
                files: ["UnixProxyProvider.cpp","UnixNetworkEnvironment.cpp","EnvironmentProxyProvider.cpp"]
                Group {
                    condition: cpp.defines.contains("HAVE_GCONF")
                    prefix: parent.prefix
                    files: ["GConfProxyProvider.cpp"]
                }
            }
            
            Group {
                condition: cpp.defines.contains("HAVE_LIBNATPMP")
                prefix: parent.prefix
                files: ["NATPMPInterface.cpp"]
            }
            Group {
                condition: cpp.defines.contains("HAVE_LIBMINIUPNPC")
                prefix: parent.prefix
                files: ["MiniUPnPInterface.cpp"]
            }
        }    
        Group {
            name: "Parser"
            prefix: "Parser/"
            files: [
                "AttributeMap.cpp",
                "AuthRequestParser.cpp",
                "AuthChallengeParser.cpp",
                "AuthSuccessParser.cpp",
                "AuthResponseParser.cpp",
                "CompressParser.cpp",
                "ElementParser.cpp",
                "IQParser.cpp",
                "MessageParser.cpp",
                "PayloadParser.cpp",
                "StanzaAckParser.cpp",
                "BOSHBodyExtractor.cpp",
                "ComponentHandshakeParser.cpp",
                "PayloadParserFactory.cpp",
                "PayloadParserFactoryCollection.cpp",
                "PayloadParsers/BodyParser.cpp",
                "PayloadParsers/SubjectParser.cpp",
                "PayloadParsers/ThreadParser.cpp",
                "PayloadParsers/CarbonsEnableParser.cpp",
                "PayloadParsers/CarbonsDisableParser.cpp",
                "PayloadParsers/CarbonsPrivateParser.cpp",
                "PayloadParsers/CarbonsReceivedParser.cpp",
                "PayloadParsers/CarbonsSentParser.cpp",
                "PayloadParsers/ChatStateParser.cpp",
                "PayloadParsers/ClientStateParser.cpp",
                "PayloadParsers/CapsInfoParser.cpp",
                "PayloadParsers/DiscoInfoParser.cpp",
                "PayloadParsers/DiscoItemsParser.cpp",
                "PayloadParsers/ErrorParser.cpp",
                "PayloadParsers/FormParser.cpp",
                "PayloadParsers/IBBParser.cpp",
                "PayloadParsers/JingleParser.cpp",
                "PayloadParsers/JingleReasonParser.cpp",
                "PayloadParsers/JingleContentPayloadParser.cpp",
                "PayloadParsers/JingleIBBTransportMethodPayloadParser.cpp",
                "PayloadParsers/JingleS5BTransportMethodPayloadParser.cpp",
                "PayloadParsers/JingleFileTransferDescriptionParser.cpp",
                "PayloadParsers/JingleFileTransferHashParser.cpp",
                "PayloadParsers/JingleFileTransferFileInfoParser.cpp",
                "PayloadParsers/StreamInitiationFileInfoParser.cpp",
                "PayloadParsers/CommandParser.cpp",
                "PayloadParsers/InBandRegistrationPayloadParser.cpp",
                "PayloadParsers/SearchPayloadParser.cpp",
                "PayloadParsers/FullPayloadParserFactoryCollection.cpp",
                "PayloadParsers/PriorityParser.cpp",
                "PayloadParsers/PrivateStorageParser.cpp",
                "PayloadParsers/RawXMLPayloadParser.cpp",
                "PayloadParsers/ResourceBindParser.cpp",
                "PayloadParsers/RosterItemExchangeParser.cpp",
                "PayloadParsers/RosterParser.cpp",
                "PayloadParsers/SecurityLabelParser.cpp",
                "PayloadParsers/SecurityLabelsCatalogParser.cpp",
                "PayloadParsers/SoftwareVersionParser.cpp",
                "PayloadParsers/StorageParser.cpp",
                "PayloadParsers/StatusParser.cpp",
                "PayloadParsers/StatusShowParser.cpp",
                "PayloadParsers/StreamInitiationParser.cpp",
                "PayloadParsers/BytestreamsParser.cpp",
                "PayloadParsers/VCardParser.cpp",
                "PayloadParsers/VCardUpdateParser.cpp",
                "PayloadParsers/DelayParser.cpp",
                "PayloadParsers/MIXParticipantParser.cpp",
                "PayloadParsers/MIXSetNickParser.cpp",
                "PayloadParsers/MIXRegisterNickParser.cpp",
                "PayloadParsers/MIXDestroyParser.cpp",
                "PayloadParsers/MIXCreateParser.cpp",
                "PayloadParsers/MIXPayloadParser.cpp",
                "PayloadParsers/MIXLeaveParser.cpp",
                "PayloadParsers/MIXJoinParser.cpp",
                "PayloadParsers/MIXUserPreferenceParser.cpp",
                "PayloadParsers/MIXUpdateSubscriptionParser.cpp",
                "PayloadParsers/MUCUserPayloadParser.cpp",
                "PayloadParsers/MUCAdminPayloadParser.cpp",
                "PayloadParsers/MUCOwnerPayloadParser.cpp",
                "PayloadParsers/MUCDestroyPayloadParser.cpp",
                "PayloadParsers/MUCInvitationPayloadParser.cpp",
                "PayloadParsers/MUCItemParser.cpp",
                "PayloadParsers/NicknameParser.cpp",
                "PayloadParsers/ReplaceParser.cpp",
                "PayloadParsers/LastParser.cpp",
                "PayloadParsers/IdleParser.cpp",
                "PayloadParsers/S5BProxyRequestParser.cpp",
                "PayloadParsers/DeliveryReceiptParser.cpp",
                "PayloadParsers/DeliveryReceiptRequestParser.cpp",
                "PayloadParsers/UserLocationParser.cpp",
                "PayloadParsers/UserTuneParser.cpp",
                "PayloadParsers/WhiteboardParser.cpp",
                "PayloadParsers/PubSubErrorParserFactory.cpp",
                "PayloadParsers/ResultSetParser.cpp",
                "PayloadParsers/ForwardedParser.cpp",
                "PayloadParsers/MAMFinParser.cpp",
                "PayloadParsers/MAMResultParser.cpp",
                "PayloadParsers/MAMQueryParser.cpp",
                "PayloadParsers/IsodeIQDelegationParser.cpp",
                "PlatformXMLParserFactory.cpp",
                "PresenceParser.cpp",
                "SerializingParser.cpp",
                "StanzaParser.cpp",
                "StreamErrorParser.cpp",
                "StreamFeaturesParser.cpp",
                "StreamManagementEnabledParser.cpp",
                "StreamResumeParser.cpp",
                "StreamResumedParser.cpp",
                "Tree/ParserElement.cpp",
                "Tree/NullParserElement.cpp",
                "Tree/TreeReparser.cpp",
                "XMLParser.cpp",
                "XMLParserClient.cpp",
                "XMLParserFactory.cpp",
                "XMPPParser.cpp",
                "XMPPParserClient.cpp"
            ]
            Group {
                condition: cpp.defines.contains("HAVE_EXPAT")
                prefix: parent.prefix
                files: ["ExpatParser.cpp"]
            }
            Group {
                condition: cpp.defines.contains("HAVE_LIBXML")
                prefix: parent.prefix
                files: ["LibXMLParser.cpp"]
            }
        }
        Group {
            name: "Presence"
            prefix: "Presence/"
            files: [
                "PresenceOracle.cpp",
                "PresenceSender.cpp",
                "DirectedPresenceSender.cpp",
                "PayloadAddingPresenceSender.cpp",
                "StanzaChannelPresenceSender.cpp",
                "SubscriptionManager.cpp"
            ]
        }
        Group {
            name: "PubSub"
            prefix: "PubSub/"
            files: [
                "PubSubManager.cpp",
                "PubSubManagerImpl.cpp"
            ]
        }
        Group {
            name: "Queries"
            prefix: "Queries/"
            files: [
                "IQChannel.cpp",
                "IQHandler.cpp",
                "IQRouter.cpp",
                "Request.cpp",
                "Responders/SoftwareVersionResponder.cpp"
            ]
        }
        Group {
            name: "Roster"
            prefix: "Roster/"
            files: [
                "RosterStorage.cpp",
                "RosterMemoryStorage.cpp",
                "XMPPRoster.cpp",
                "XMPPRosterImpl.cpp",
                "XMPPRosterController.cpp"
            ]
        }
        Group {
            name: "SASL"
            prefix: "SASL/"
            files: [
                "ClientAuthenticator.cpp",
                "EXTERNALClientAuthenticator.cpp",
                "PLAINClientAuthenticator.cpp",
                "PLAINMessage.cpp",
                "SCRAMSHA1ClientAuthenticator.cpp",
                "DIGESTMD5Properties.cpp",
                "DIGESTMD5ClientAuthenticator.cpp"
            ]
            Group {
                condition: qbs.targetOS.contains("windows")
                prefix: parent.prefix
                files: [   
                    "WindowsServicePrincipalName.cpp",
                    "WindowsAuthentication.cpp",
                    "WindowsGSSAPIClientAuthenticator.cpp"
                ]
            }
        }
        Group {
            name: "Serializer"
            prefix: "Serializer/"
            files: [
                "AuthRequestSerializer.cpp",
                "AuthSuccessSerializer.cpp",
                "AuthChallengeSerializer.cpp",
                "AuthResponseSerializer.cpp",
                "CompressRequestSerializer.cpp",
                "ElementSerializer.cpp",
                "MessageSerializer.cpp",
                "StreamManagementEnabledSerializer.cpp",
                "StreamResumeSerializer.cpp",
                "StreamResumedSerializer.cpp",
                "ComponentHandshakeSerializer.cpp",
                "PayloadSerializer.cpp",
                "PayloadSerializerCollection.cpp",
                "PayloadSerializers/IBBSerializer.cpp",
                "PayloadSerializers/CapsInfoSerializer.cpp",
                "PayloadSerializers/CarbonsDisableSerializer.cpp",
                "PayloadSerializers/CarbonsEnableSerializer.cpp",
                "PayloadSerializers/CarbonsPrivateSerializer.cpp",
                "PayloadSerializers/CarbonsSentSerializer.cpp",
                "PayloadSerializers/CarbonsReceivedSerializer.cpp",
                "PayloadSerializers/ChatStateSerializer.cpp",
                "PayloadSerializers/ClientStateSerializer.cpp",
                "PayloadSerializers/DiscoInfoSerializer.cpp",
                "PayloadSerializers/DiscoItemsSerializer.cpp",
                "PayloadSerializers/ErrorSerializer.cpp",
                "PayloadSerializers/FullPayloadSerializerCollection.cpp",
                "PayloadSerializers/MIXParticipantSerializer.cpp",
                "PayloadSerializers/MIXSetNickSerializer.cpp",
                "PayloadSerializers/MIXRegisterNickSerializer.cpp",
                "PayloadSerializers/MIXDestroySerializer.cpp",
                "PayloadSerializers/MIXCreateSerializer.cpp",
                "PayloadSerializers/MIXPayloadSerializer.cpp",
                "PayloadSerializers/MIXUserPreferenceSerializer.cpp",
                "PayloadSerializers/MIXLeaveSerializer.cpp",
                "PayloadSerializers/MIXJoinSerializer.cpp",
                "PayloadSerializers/MIXUpdateSubscriptionSerializer.cpp",
                "PayloadSerializers/MUCPayloadSerializer.cpp",
                "PayloadSerializers/MUCUserPayloadSerializer.cpp",
                "PayloadSerializers/MUCAdminPayloadSerializer.cpp",
                "PayloadSerializers/MUCOwnerPayloadSerializer.cpp",
                "PayloadSerializers/MUCDestroyPayloadSerializer.cpp",
                "PayloadSerializers/MUCInvitationPayloadSerializer.cpp",
                "PayloadSerializers/ResourceBindSerializer.cpp",
                "PayloadSerializers/RosterItemExchangeSerializer.cpp",
                "PayloadSerializers/RosterSerializer.cpp",
                "PayloadSerializers/SecurityLabelSerializer.cpp",
                "PayloadSerializers/SecurityLabelsCatalogSerializer.cpp",
                "PayloadSerializers/SoftwareVersionSerializer.cpp",
                "PayloadSerializers/StreamInitiationSerializer.cpp",
                "PayloadSerializers/BytestreamsSerializer.cpp",
                "PayloadSerializers/VCardSerializer.cpp",
                "PayloadSerializers/VCardUpdateSerializer.cpp",
                "PayloadSerializers/StorageSerializer.cpp",
                "PayloadSerializers/PrivateStorageSerializer.cpp",
                "PayloadSerializers/DelaySerializer.cpp",
                "PayloadSerializers/CommandSerializer.cpp",
                "PayloadSerializers/InBandRegistrationPayloadSerializer.cpp",
                "PayloadSerializers/SearchPayloadSerializer.cpp",
                "PayloadSerializers/FormSerializer.cpp",
                "PayloadSerializers/NicknameSerializer.cpp",
                "PayloadSerializers/JingleFileTransferDescriptionSerializer.cpp",
                "PayloadSerializers/JinglePayloadSerializer.cpp",
                "PayloadSerializers/JingleContentPayloadSerializer.cpp",
                "PayloadSerializers/JingleFileTransferHashSerializer.cpp",
                "PayloadSerializers/JingleIBBTransportPayloadSerializer.cpp",
                "PayloadSerializers/JingleS5BTransportPayloadSerializer.cpp",
                "PayloadSerializers/StreamInitiationFileInfoSerializer.cpp",
                "PayloadSerializers/DeliveryReceiptSerializer.cpp",
                "PayloadSerializers/DeliveryReceiptRequestSerializer.cpp",
                "PayloadSerializers/UserLocationSerializer.cpp",
                "PayloadSerializers/UserTuneSerializer.cpp",
                "PayloadSerializers/WhiteboardSerializer.cpp",
                "PayloadSerializers/ResultSetSerializer.cpp",
                "PayloadSerializers/ForwardedSerializer.cpp",
                "PayloadSerializers/MAMFinSerializer.cpp",
                "PayloadSerializers/MAMResultSerializer.cpp",
                "PayloadSerializers/MAMQuerySerializer.cpp",
                "PayloadSerializers/IsodeIQDelegationSerializer.cpp",
                "PayloadSerializers/JingleFileTransferFileInfoSerializer.cpp",
                "PayloadSerializers/ThreadSerializer.cpp",
                "PresenceSerializer.cpp",
                "StanzaSerializer.cpp",
                "StreamErrorSerializer.cpp",
                "StreamFeaturesSerializer.cpp",
                "XML/XMLElement.cpp",
                "XML/XMLNode.cpp",
                "XMPPSerializer.cpp"
            ]
        }
        Group {
            name: "Session"
            prefix: "Session/"
            files: [
                "Session.cpp",
                "SessionTracer.cpp",
                "SessionStream.cpp",
                "BasicSessionStream.cpp",
                "BOSHSessionStream.cpp"
            ]
        }
        Group {
            name: "StreamManagement"
            prefix: "StreamManagement/"
            files: [
                "StanzaAckRequester.cpp",
                "StanzaAckResponder.cpp"
            ]
        }
        Group {
            name: "StreamStack"
            prefix: "StreamStack/"
            files: [
                "HighLayer.cpp",
                "LowLayer.cpp",
                "StreamStack.cpp",
                "ConnectionLayer.cpp",
                "TLSLayer.cpp",
                "WhitespacePingLayer.cpp",
                "XMPPLayer.cpp"
            ]
        }
        Group {
            name: "StringCodecs"
            prefix: "StringCodecs/"
            files: [
                "Base64.cpp",
                "Hexify.cpp",
            ]
            Group {
                condition: qbs.targetOS.contains("windows")
                prefix: parent.prefix
                files: ["SHA1_Windows.cpp"]
            }
        }
        Group {
            name: "TLS"
            prefix: "TLS/"
            files: [
                "Certificate.cpp",
                "CertificateFactory.cpp",
                "CertificateTrustChecker.cpp",
                "ServerIdentityVerifier.cpp",
                "TLSContext.cpp",
                "TLSContextFactory.cpp",
                "PlatformTLSFactories.cpp"
            ]
            Group {
                condition: cpp.defines.contains("HAVE_OPENSSL")
                prefix: parent.prefix
                files: [
                    "OpenSSL/OpenSSLContext.cpp",
                    "OpenSSL/OpenSSLCertificate.cpp",
                    "OpenSSL/OpenSSLContextFactory.cpp",
                ]
            }
            Group {
                condition: cpp.defines.contains("HAVE_SCHANNEL")
                prefix: parent.prefix
                files: [
                    "CAPICertificate.cpp",
                    "Schannel/SchannelContext.cpp",
                    "Schannel/SchannelCertificate.cpp",
                    "Schannel/SchannelContextFactory.cpp"
                ]
            }
            Group {
                condition: cpp.defines.contains("HAVE_SECURETRANSPORT")
                prefix: parent.prefix
                files: [
                    "SecureTransport/SecureTransportContext.mm",
                    "SecureTransport/SecureTransportCertificate.mm",
                    "SecureTransport/SecureTransportContextFactory.cpp"
                ]
            }
        }
        Group {
            name: "VCards"
            prefix: "VCards/"
            files: [
                "VCardManager.cpp",
                "VCardStorage.cpp"
            ]
        }
        Group {
            name: "Whiteboard"
            prefix: "Whiteboard/"
            files: [
                "WhiteboardResponder.cpp",
                "WhiteboardSession.cpp",
                "IncomingWhiteboardSession.cpp",
                "OutgoingWhiteboardSession.cpp",
                "WhiteboardSessionManager.cpp",
                "WhiteboardServer.cpp",
                "WhiteboardClient.cpp",
                "WhiteboardTransformer.cpp",
            ]
        }

        Group {
            name: "elements"
            files: {
                var sources = []
                var elements = [
                    "PubSub", "PubSubAffiliations", "PubSubAffiliation", "PubSubConfigure", "PubSubCreate", "PubSubDefault",
                    "PubSubItems", "PubSubItem", "PubSubOptions", "PubSubPublish", "PubSubRetract", "PubSubSubscribeOptions",
                    "PubSubSubscribe", "PubSubSubscriptions", "PubSubSubscription", "PubSubUnsubscribe",

                    "PubSubEvent", "PubSubEventAssociate", "PubSubEventCollection", "PubSubEventConfiguration", "PubSubEventDelete",
                    "PubSubEventDisassociate", "PubSubEventItem", "PubSubEventItems", "PubSubEventPurge", "PubSubEventRedirect",
                    "PubSubEventRetract", "PubSubEventSubscription",

                    "PubSubOwnerAffiliation", "PubSubOwnerAffiliations", "PubSubOwnerConfigure", "PubSubOwnerDefault",
                    "PubSubOwnerDelete", "PubSubOwnerPubSub", "PubSubOwnerPurge", "PubSubOwnerRedirect",
                    "PubSubOwnerSubscription", "PubSubOwnerSubscriptions",

                    "PubSubError"
                ]
                for (var i in elements) {
                    var element = elements[i]
                    sources.concat([
                        "Elements/" + element + ".cpp",
                        "Serializer/PayloadSerializers/" + element + "Serializer.cpp",
                        "Parser/PayloadParsers/" + element + "Parser.cpp"
                    ])
                }
                return sources
            }
        }

        Export {
            Depends { name: "cpp" }
            Depends { name: "Boost" }
            cpp.defines: product.cpp.defines.concat(["HAVE_" + product.name.toUpperCase()])
            cpp.includePaths: product.cpp.includePaths
        }

        Group {
            qbs.install: true
            fileTagsFilter: product.type
        }
    }
}