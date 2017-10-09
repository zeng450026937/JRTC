import qbs

Product {
    name: "LibNATPMP"
    type: "staticlibrary"

    Depends {
        name: "cpp"
    }
    cpp.includePaths: [
        "src",
        "src/libnatpmp"
    ]

    cpp.defines: [
        "NDEBUG",
        "STATICLIB"
    ]

    Properties {
        condition: qbs.targetOS.contains("darwin")
        cpp.defines: outer.concat(["MACOSX","_DARWIN_C_SOURCE"])
    }
    Properties {
        condition: qbs.targetOS.contains("windows")
        cpp.defines: outer.concat(["WIN32"])
    }

    Group {
        name: "source files"
        prefix: "src/"
        files: [
            "libnatpmp/getgateway.c",
            "libnatpmp/natpmp.c",
            "libnatpmp/natpmpc.c",
        ]
    }
    Group {
        condition: qbs.targetOS.contains("windows")
        prefix: "src/"
        files: [
            "libnatpmp/wingettimeofday.c"
        ]
    }

    Export {
        Depends { name: "cpp" }
        cpp.defines: ["HAVE_" + product.name.toUpperCase()]
        cpp.includePaths: product.cpp.includePaths
    }

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}
