import qbs

CppApplication {
    name: "MUCListAndJoin"
    consoleApplication: true

    Depends { 
        name: "JXMPP"
        cpp.link: true
        cpp.linkWholeArchive: false
    }

    files: [ "MUCListAndJoin.cpp" ]

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}