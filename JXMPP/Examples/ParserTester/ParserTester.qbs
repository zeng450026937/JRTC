import qbs

CppApplication {
    name: "ParserTester"
    consoleApplication: true

    Depends { 
        name: "JXMPP"
        cpp.link: false
        cpp.linkWholeArchive: false
    }

    files: [ "ParserTester.cpp" ]

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}