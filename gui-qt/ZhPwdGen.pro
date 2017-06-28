#-------------------------------------------------
#
# Project created by QtCreator 2017-06-24T01:44:19
#
#-------------------------------------------------

QT     += core gui widgets
CONFIG += c++11

TARGET = ZhPwdGen
TEMPLATE = app
QMAKE_CXXFLAGS += -utf-8
QMAKE_CXXFLAGS += -wd4018   # ignore warnings for signed/unsigned comparison

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += SODIUM_STATIC= 1 SODIUM_EXPORT=          # needed for static linking with libsodium
INCLUDEPATH += "C:\libsodium-1.0.12-msvc\include"
CONFIG(release, debug|release) {
    LIBS += C:\libsodium-1.0.12-msvc\Win32\Release\v140\static\libsodium.lib
} else {
    LIBS += C:\libsodium-1.0.12-msvc\Win32\Debug\v140\static\libsodium.lib
}

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    passwordview.cpp \
    wordsepview.cpp \
    passwordgenerator.cpp \
    entropyview.cpp \
    passwordcontrol.cpp \
    password.cpp

HEADERS += \
    mainwindow.h \
    passwordview.h \
    wordsepview.h \
    passwordgenerator.h \
    password.h \
    entropyview.h \
    passwordcontrol.h
