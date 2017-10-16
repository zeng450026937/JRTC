import qbs

Project {
    CppApplication {
        name: "ReceiveFile"
        consoleApplication: true

        Depends { 
            name: "JXMPP"
            cpp.link: true
            cpp.linkWholeArchive: false
        }

        files: [ "ReceiveFile.cpp" ]

        Group {
            qbs.install: true
            fileTagsFilter: product.type
        }
    }
    CppApplication {
        name: "SendFile"
        consoleApplication: true

        Depends { 
            name: "JXMPP"
            cpp.link: true
            cpp.linkWholeArchive: false
        }

        files: [ "SendFile.cpp" ]

        Group {
            qbs.install: true
            fileTagsFilter: product.type
        }
    }
}