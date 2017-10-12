import qbs

CppApplication {
    name: "BenchTool"
    consoleApplication: true

    Depends { 
        name: "JXMPP"
        cpp.link: false
        cpp.linkWholeArchive: false
    }

    files: [ "BenchTool.cpp" ]

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}