import qbs

Product {
    name: "SQLite"
    type: "staticlibrary"
    //type: "dynamiclibrary"

    Depends {
        name: "cpp"
    }
    cpp.defines: []
    cpp.includePaths: ["."]

    Group {
        name: "source files"
        files: ["sqlite3.c"]
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
