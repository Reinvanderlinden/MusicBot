TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
TARGET =curl

LIBS += -lcurl

SOURCES += \
        main.cpp
