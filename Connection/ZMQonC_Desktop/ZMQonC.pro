CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

LIBS += -lcurl

DEFINES += ZMQ_STATIC
LIBS += -L$$PWD/../lib -lzmq -lws2_32 -lIphlpapi
INCLUDEPATH += $$PWD/../include

SOURCES += main.c
