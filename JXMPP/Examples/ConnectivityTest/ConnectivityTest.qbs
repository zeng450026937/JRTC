import qbs

CppApplication {
    name: "ConnectivityTest"
    consoleApplication: true

    Depends {
        name: "cpp"
    }
    Depends {
        name: "Boost"
        cpp.link: true
        cpp.linkWholeArchive: false
    }
    Depends { 
        name: "JXMPP"
        cpp.link: false
        cpp.linkWholeArchive: false
    }

    files: [ "ConnectivityTest.cpp" ]

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}