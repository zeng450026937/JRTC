import qbs

Product {
    name: "ZLib"
    type: "staticlibrary"
    //type: "dynamiclibrary"

    Depends {
        name: "cpp"
    }
    cpp.defines: []
    cpp.includePaths: ["src"]

    Group {
        name: "source files"
        prefix: "src/"
        files: ["adler32.c", "compress.c", "crc32.c", "deflate.c", "gzio.c", "infback.c", "inffast.c", "inflate.c", "inftrees.c", "trees.c", "uncompr.c", "zutil.c"]
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
