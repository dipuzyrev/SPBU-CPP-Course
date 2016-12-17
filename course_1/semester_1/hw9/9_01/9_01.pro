TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    PriorityQueue.cpp \
    CustomString.cpp \
    DeikstraSearch.cpp

HEADERS += \
    PriorityQueue.h \
    CustomString.h \
    DeikstraSearch.h
