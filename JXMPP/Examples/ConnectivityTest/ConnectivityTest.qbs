import qbs

CppApplication {
    name: "ConnectivityTest"
    consoleApplication: true

    Depends { 
        name: "JXMPP"
        cpp.link: true
        cpp.linkWholeArchive: false
    }

    files: [ "ConnectivityTest.cpp" ]

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}