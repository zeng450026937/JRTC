import qbs

CppApplication {
    name: "LinkLocalTool"
    consoleApplication: true

    Depends { 
        name: "JXMPP"
        cpp.link: true
        cpp.linkWholeArchive: false
    }

    files: [ "LinkLocalTool.cpp" ]

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}