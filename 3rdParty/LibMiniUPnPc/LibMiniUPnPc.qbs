import qbs

Product {
    name: "LibMiniUPnPc"
    type: "staticlibrary"
    //type: "dynamiclibrary"

    property stringList libraries: ["Ws2_32", "Iphlpapi"]

    Depends {
        name: "cpp"
    }
    cpp.includePaths: [
        "src",
        "src/miniupnpc"
    ]

    cpp.defines: [
        "NDEBUG",
        "MINIUPNP_STATICLIB"
    ]

    cpp.dynamicLibraries: libraries

    Properties {
        condition: qbs.targetOS.contains("darwin")
        cpp.defines: outer.concat(["MACOSX","_DARWIN_C_SOURCE"])
    }
    Properties {
        condition: qbs.targetOS.contains("windows")
        cpp.defines: outer.concat(["WIN32","_WIN32_WINNT=0x0501"])
    }
    Properties {
        condition: !qbs.targetOS.contains("windows")
        cpp.defines: outer.concat([
            "_BSD_SOURCE",
            "MINIUPNPC_SET_SOCKET_TIMEOUT"
        ])
    }

    Group {
        name: "source files"
        prefix: "src/"
        files: [
            "miniupnpc/connecthostport.c",
            "miniupnpc/igd_desc_parse.c",
            "miniupnpc/minisoap.c",
            "miniupnpc/minissdpc.c",
            "miniupnpc/miniupnpc.c",
            "miniupnpc/miniwget.c",
            "miniupnpc/minixml.c",
            "miniupnpc/portlistingparse.c",
            "miniupnpc/receivedata.c",
            "miniupnpc/upnpcommands.c",
            "miniupnpc/upnpdev.c",
            "miniupnpc/upnperrors.c",
            "miniupnpc/upnpreplyparse.c",
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
