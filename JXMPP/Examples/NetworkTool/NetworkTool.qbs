import qbs

CppApplication {
    name: "NetworkTool"
    consoleApplication: true

    Depends { 
        name: "JXMPP"
        cpp.link: true
        cpp.linkWholeArchive: false
    }

    files: [ "NetworkTool.cpp" ]

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}