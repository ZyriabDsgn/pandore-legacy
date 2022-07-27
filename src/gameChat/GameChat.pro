TEMPLATE = app
QT += gui core network
greaterThan(QT_MAJOR_VERSION, 4) QT += widgets

#input

HEADERS += GameChatView.h \
           GameChatModel.h

SOURCES += main.cpp \
           GameChatView.cpp \
           GameChatModel.cpp
