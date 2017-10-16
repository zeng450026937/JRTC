import qbs

CppApplication {
    name: "SendMessage"
    consoleApplication: true

    Depends { 
        name: "JXMPP"
        //cpp.link: false
        //cpp.linkWholeArchive: false
    }

    files: [ "SendMessage.cpp" ]

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}