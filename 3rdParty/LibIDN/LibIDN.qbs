import qbs

Product {
    name: "LibIDN"
    type: "staticlibrary"

    Depends {
        name: "cpp"
    }
    cpp.defines: ["LIBIDN_STATIC", "HAVE_CONFIG_H", "strcasecmp=stricmp", "strncasecmp=strnicmp"]
    cpp.includePaths: ["src", "stubs", "src/gl"]

    Group {
        name: "source file"
        prefix: "src/"
        files: ["stringprep.c", "profiles.c", "rfc3454.c", "punycode.c", "idna.c", "toutf8.c", "nfkc.c", "gl/c-ctype.c", "gl/c-strcasecmp.c", "gl/c-strncasecmp.c", "gl/unistr/u8-check.c"]
    }

    Properties {
        condition: qbs.targetOS.contains("windows")
        cpp.includePaths: outer.concat(["stubs/win32"])

        Properties {
            condition: qbs.toolchains.contains("msvc")
            cpp.includePaths: {

                if (cpp.compilerVersionMajor < 14) {
                    return outer.concat(["stubs/win32/stdbool"])
                }
                if (cpp.compilerVersionMajor == 15) {
                    return outer.concat(["stubs/win32/VC2008"])
                }
                
                return outer
            }
        }
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
