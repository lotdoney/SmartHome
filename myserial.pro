#-------------------------------------------------
#
# Project created by QtCreator 2016-03-07T16:37:02
#
#-------------------------------------------------

QT += core
QT += core gui
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DLL QWT_DLL



CONFIG(debug,debug|release) {
    LIBS += -L"E:\Qt\Qt5.3.2\5.3\mingw482_32\lib" -lqwtd
} else {
    LIBS += -L"E:\Qt\Qt5.3.2\5.3\mingw482_32\lib" -lqwt
}

INCLUDEPATH += E:\Qt\Qt5.3.2\5.3\mingw482_32\include\Qwt



#TARGET = intelligent
#TEMPLATE = app

#ICON +=


TEMPLATE = app
TARGET = intelligent


include(SerialPort/SerialPort.pri)
include(MainWindow/MainWindow.pri)
include(StatueDialog/StatueDialog.pri)
include(AirDialog/AirDialog.pri)
include(PowerDialog/PowerDialog.pri)
include(misc/timer/timeDialog.pri)
include(misc/TTS/TTS.pri)
include(misc/Recipes/RecipeRequest.pri)
include(misc/camera/camera.pri)

#SUBDIRS += misc/misc.pro \

CONFIG += ordered

SOURCES += \
    light_window_dialog.cpp \

HEADERS  += \
    light_window_dialog.h \
    commonhelper.h \

FORMS    +=  \
    light_window_dialog.ui

RESOURCES += \
    resource.qrc



####################### OPENCV ######################################





