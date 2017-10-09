import qbs

Product {
    name: "Expat"
    type: "staticlibrary"

    Depends {
        name: "cpp"
    }
    cpp.includePaths: [".", "src"]

    Properties {
        condition: qbs.toolchain.contains("msvc")
        cpp.defines: outer.concat(["_CRT_SECURE_NO_WARNINGS","-wd4996"])
    }
    Properties {
        condition: product.type == "staticlibrary"
        cpp.defines: outer.concat(["XML_STATIC"])
    }
    
    Group {
        name: "source files"
        prefix: "src/"
        files: [
            "loadlibrary.c",
            "xmlparse.c",
            "xmlrole.c",
            "xmltok.c",
            "xmltok_impl.c",
            "xmltok_ns.c"
        ]
    }
    Group {
        condition: product.type == "dynamiclibrary"
        prefix: "src/"
        files: ["libexpat.def"]
    }

    Export {
        Depends { name: "cpp" }
        cpp.defines: ["HAVE_" + product.name.toUpperCase()]
        cpp.includePaths: [qbs.installRoot + "/" + product.name]
    }

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
    Group {
        qbs.install: true
        qbs.installDir: product.name
        prefix: "src/"
        files: ["expat.h","expat_external.h"]
    }
}
