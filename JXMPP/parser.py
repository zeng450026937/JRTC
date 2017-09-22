#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os
import os.path
import re

rootdir = os.path.curdir

replaceMap = {
"namespace Swift": "namespace JXMPP",
"SWIFTEN_": "JXMPP_",
"SWIFT_": "JXMPP_",
"SWIFT_SWIFTEN_": "JXMPP_",
"SWIFTEN_BUILDING": "JXMPP_EXPORT",
"Swift::": "JXMPP::",
"#include <Swiften": "#include <JXMPP",
"#pragma once": "",
'"Swift"': '"JXMPP"'
}

for year in range(2010, 2017+1):
    delta = 2017-year
    for step in range(1, delta+1):
        copyRight = {
"""/*
 * Copyright (c) %d-%d Isode Limited.
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */
""" % (year,year+step): "",

"""/*
 * Copyright (c) %d-%d Isode Limited.
 * All right reserved.
 * See the COPYING file for more information.
 */
""" % (year,year+step): "",

"""/*
 * Copyright (c) %d-%d Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */
""" % (year,year+step): ""
        }
        replaceMap.update(copyRight)

    copyRight = {
"""/*
 * Copyright (c) %d Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */
""" % (year): "",

"""/*
 * Copyright (c) %d Isode Limited, London, England.
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */
""" % (year): "",

"""/*
 * Copyright (c) %d Isode Limited.
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */
""" % (year): ""
    }
    replaceMap.update(copyRight)

for parent,dirnames,filenames in os.walk(rootdir):
    print("=== DIR LIST ===")
    for dirname in  dirnames:  
        print("dirname:",dirname)

    print("=== FILE LIST ===")
    for filename in filenames:
        filePath = os.path.join(parent, filename)
        fileAbsPath = os.path.abspath(os.path.join(parent, filename))
        fileBase, fileExt = os.path.splitext(filename)

        print("filename:" ,filename)
        #print("filebase:", fileBase)
        #print("fileext:", fileExt)
        #print("filepath:", filePath)
        #print("fileabspath:", fileAbsPath)

        if fileExt == ".obj" or fileExt == ".pdb" or fileExt == ".obj.pdb" or fileBase == "SConscript":
            os.remove(filePath)

        if fileExt == ".h" or fileExt == ".cpp" or fileExt == ".mm":
            fileObject = open(filePath, 'r', encoding="utf-8")
            
            fileObject.seek(0, 0)
            fileString = fileObject.read()
            fileObject.close()

            headerString = "JXMPP_" + fileBase.upper() +"_H"

            if fileExt == ".h":
                replaceMap.update({"#ifndef %s\n" % (headerString): ""})
                replaceMap.update({"#define %s\n" % (headerString): ""})
                replaceMap.update({"#endif // %s\n" % (headerString): ""})

            for item in replaceMap.items():
                fileString = fileString.replace(item[0], item[1])
            
            fileString = fileString.splitlines(True)

            i = 0
            while fileString[i] == "\n":
                fileString[i] = ""
                i += 1
            i = len(fileString)-1
            while fileString[i] == "\n":
                fileString[i] = ""
                i -= 1

            fileContent = []
            
            if fileExt == ".h":
                fileContent.append("#ifndef %s\n" % (headerString))
                fileContent.append("#define %s\n" % (headerString))
                fileContent.append("\n")
                fileContent.extend(fileString)
                fileContent.append("\n")
                fileContent.append("#endif // %s\n" % (headerString))
            else:
                fileContent.extend(fileString)
                
            fileObject = open(filePath, 'w', encoding="utf-8")
            fileObject.seek(0, 0)
            fileObject.writelines(fileContent)
            fileObject.flush()
            fileObject.close()