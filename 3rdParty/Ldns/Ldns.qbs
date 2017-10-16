import qbs

Product {
    name: "Ldns"
    type: "staticlibrary"
    //type: "dynamiclibrary"

    Depends {
        name: "cpp"
    }
    Depends {
        name: "OpenSSL"
    }
    cpp.includePaths: [".","src/ldns"]
    cpp.defines: [
        "HAVE_ISBLANK",
        "HAVE_STRUCT_ADDRINFO",
        "HAVE_CONFIG_H",
        "_CRT_SECURE_NO_DEPRECATE"
    ]

    Properties {
        condition: qbs.targetOS.contains("android")
        cpp.includePaths: outer.concat(["src/android"])
    }
    Properties {
        condition: product.type == "staticlibrary"
        cpp.defines: outer.concat(["LDNS_STATICLIB"])
    }
    
    Group {
        name: "source files"
        prefix: "src/"
        files: [
            "ldns/compat/b32_ntop.c",
            "ldns/compat/b32_pton.c",
            "ldns/compat/b64_ntop.c",
            "ldns/compat/b64_pton.c",
            "ldns/compat/gettimeofday.c",
            "ldns/compat/localtime_r.c",
            "ldns/compat/strlcpy.c",
            "ldns/buffer.c",
            "ldns/dname.c",
            "ldns/dnssec_sign.c",
            "ldns/dnssec_verify.c",
            "ldns/dnssec_zone.c",
            "ldns/dnssec.c",
            "ldns/error.c",
            "ldns/higher.c",
            "ldns/host2str.c",
            "ldns/host2wire.c",
            "ldns/keys.c",
            "ldns/linktest.c",
            "ldns/net.c",
            "ldns/packet.c",
            "ldns/parse.c",
            "ldns/rbtree.c",
            "ldns/rdata.c",
            "ldns/resolver.c",
            "ldns/rr_functions.c",
            "ldns/rr.c",
            "ldns/sha1.c",
            "ldns/sha2.c",
            "ldns/str2host.c",
            "ldns/tsig.c",
            "ldns/update.c",
            "ldns/util.c",
            "ldns/wire2host.c",
            "ldns/zone.c",
        ]
    }

    Export {
        Depends { name: "cpp" }
        cpp.defines: product.cpp.defines.concat(["HAVE_" + product.name.toUpperCase()])
        cpp.includePaths: product.cpp.includePaths
    }

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }   
}
