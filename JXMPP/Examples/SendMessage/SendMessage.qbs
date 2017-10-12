import qbs

CppApplication {
    name: "SendMessage"
    consoleApplication: true

    Depends { 
        name: "JXMPP"
        cpp.link: true
        cpp.linkWholeArchive: false
    }

    files: [ "SendMessage.cpp" ]

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}