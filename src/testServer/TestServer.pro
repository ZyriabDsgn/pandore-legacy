TEMPLATE=app
QT += gui core network
greaterThan(QT_MAJOR_VERSION, 4) QT += widgets

#input

HEADERS += TestServer.h

SOURCES += TestServer.cpp \
           main.cpp
