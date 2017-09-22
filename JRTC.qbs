import qbs

Project {
    name: "JRTC"
    
    property bool BOOST_BUNDLED: true
    property bool EXPAT_BUNDLED: true
    property bool ICU_BUNDLED: true
    property bool LDNS_BUNDLED: false
    property bool LIBIDN_BUNDLED: true
    property bool LIBMINIUPNPC_BUNDLED: true
    property bool LIBNATPMP_BUNDLED: true
    property bool OPENSSL_BUNDLED: true
    property bool SQLITE_BUNDLED: true
    property bool UNBOUND_BUNDLED: false
    property bool ZLIB_BUNDLED: true
    
    references: [
        "3rdParty/3rdParty.qbs",
        "JXMPP/JXMPP.qbs"
    ]
    qbsSearchPaths: "Qbs"
}
