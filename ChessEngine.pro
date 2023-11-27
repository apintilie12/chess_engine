QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        boardwidget.cpp \
        chesspiece.cpp \
        main.cpp \
        move.cpp \
        pawn.cpp \
        square.cpp

TRANSLATIONS += \
    ChessEngine_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    boardwidget.h \
    chesspiece.h \
    move.h \
    pawn.h \
    square.h

QT += widgets

RESOURCES += \
    res.qrc
