TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    List.cpp \
    Tree.cpp \
    CustomString.cpp \
    CodesList.cpp \
    PriorityQueue.cpp

HEADERS += \
    List.h \
    Tree.h \
    CustomString.h \
    CodesList.h \
    PriorityQueue.h
