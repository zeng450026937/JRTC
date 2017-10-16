import qbs

Product {
    name: "ICU"
    type: "staticlibrary"
    //type: "dynamiclibrary"

    property stringList libraries: ["Advapi32"]

    Depends {
        name: "cpp"
    }
    cpp.defines: ["HAVE_DLOPEN=0", "U_HAVE_ATOMIC=1", "U_HAVE_MMAP=0", "U_STATIC_IMPLEMENTATION","U_USING_ICU_NAMESPACE=0"]
    cpp.includePaths: ["src/common"]
    cpp.dynamicLibraries: libraries

    Group {
        name: "stubdata"
        prefix: "src/stubdata/"
        files: ["stubdata.c"]
    }
    Group {
        name: "common"
        prefix: "src/common/"
        files: ["*.c", "*.cpp"]

        cpp.defines: outer.concat(["U_COMMON_IMPLEMENTATION"])
        cpp.includePaths: outer.concat(["src/common"])
    }
    Group {
        name: "i18n"
        prefix: "src/i18n/"
        files: ["*.c", "*.cpp"]

        cpp.defines: outer.concat(["U_I18N_IMPLEMENTATION"])
        cpp.includePaths: outer.concat(["src/i18n"])
    }
    Group {
        name: "layout"
        prefix: "src/layout/"
        files: ["*.c", "*.cpp"]

        cpp.defines: outer.concat(["U_LAYOUT_IMPLEMENTATION"])
        cpp.includePaths: outer.concat(["src", "src/layout"])
    }
    Group {
        name: "layoutex"
        prefix: "src/layoutex/"
        files: ["*.c", "*.cpp"]

        cpp.defines: outer.concat(["U_LAYOUTEX_IMPLEMENTATION"])
        cpp.includePaths: outer.concat([
            "src",
            "src/layoutex",
            "src/layoutex/unicode"
        ])
    }
    Group {
        name: "io"
        prefix: "src/io/"
        files: ["*.c", "*.cpp"]

        cpp.defines: outer.concat(["U_IO_IMPLEMENTATION"])
        cpp.includePaths: outer.concat(["src/i18n"])
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
