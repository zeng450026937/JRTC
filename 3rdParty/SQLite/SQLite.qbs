import qbs

Product {
    name: "SQLite"
    type: "staticlibrary"

    Depends {
        name: "cpp"
    }
    cpp.includePaths: ["."]

    Group {
        name: "source files"
        files: ["sqlite3.c"]
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
