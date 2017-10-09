import qbs

Project {
    name: "3rdParty"
    references: {
        var ref = []
        
        if (project.BOOST_BUNDLED)
            ref.push("Boost/Boost.qbs")
        if (project.EXPAT_BUNDLED)
            ref.push("Expat/Expat.qbs")
        if (project.ICU_BUNDLED)
            ref.push("ICU/ICU.qbs")
        if (project.LDNS_BUNDLED)
            ref.push("Ldns/Ldns.qbs")
        if (project.LIBIDN_BUNDLED)
            ref.push("LibIDN/LibIDN.qbs")
        if (project.LIBMINIUPNPC_BUNDLED)
            ref.push("LibMiniUPnPc/LibMiniUPnPc.qbs")
        if (project.LIBNATPMP_BUNDLED)
            ref.push("LibNATPMP/LibNATPMP.qbs")
        if (project.OPENSSL_BUNDLED)
            ref.push("OpenSSL/OpenSSL.qbs")
        if (project.SQLITE_BUNDLED)
            ref.push("SQlite/SQlite.qbs")
        if (project.UNBOUND_BUNDLED)
            ref.push("Unbound/Unbound.qbs")
        if (project.ZLIB_BUNDLED)
            ref.push("ZLib/ZLib.qbs")

        return ref
    }
}
