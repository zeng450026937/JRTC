QT       -= gui

TARGET = JXMPP
TEMPLATE = lib
CONFIG += static

DEFINES += $$join(TARGET,,,_EXPORT)

CONFIG(static) {
    message("jxmpp static build.")
    DEFINES += $$join(TARGET,,,_STATIC)
}

INCLUDEPATH += \
    ../ \
    JID \
    Base \
    IDN \

for(folder, INCLUDEPATH){
    SOURCES += $$files($$folder/*.cpp)
    HEADERS += $$files($$folder/*.h)
}

unix {
    target.path = /usr/lib
    INSTALLS += target
}

#LibIDN
include($$PWD/../3rdParty/LibIDN/LibIDN.pri)
DEFINES += HAVE_LIBIDN

#ZLib
include($$PWD/../3rdParty/ZLib/ZLib.pri)
DEFINES += HAVE_ZLIB

#Boost
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../3rdParty/Boost/release/ -lBoost
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../3rdParty/Boost/debug/ -lBoost
else:unix: LIBS += -L$$OUT_PWD/../3rdParty/Boost/ -lBoost

INCLUDEPATH += $$PWD/../3rdParty/Boost
INCLUDEPATH += $$PWD/../3rdParty/Boost/src
DEPENDPATH += $$PWD/../3rdParty/Boost
DEPENDPATH += $$PWD/../3rdParty/Boost/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../3rdParty/Boost/release/libBoost.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../3rdParty/Boost/debug/libBoost.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../3rdParty/Boost/release/Boost.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../3rdParty/Boost/debug/Boost.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../3rdParty/Boost/libBoost.a

