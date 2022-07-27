TEMPLATE=app
QT += core network
greaterThan(QT_MAJOR_VERSION, 4) QT += widgets

#input

HEADERS += ServerApplication.h \
           operationsEnum.h \
           ../Client.h

SOURCES += ServerApplication.cpp \
           ../Client.cpp
