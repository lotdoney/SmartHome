#-------------------------------------------------
#
# Project created by QtCreator 2016-03-07T16:37:02
#
#-------------------------------------------------

QT += core
QT += core gui
QT += serialport

DEFINES += QT_DLL QWT_DLL



CONFIG(debug,debug|release) {
    LIBS += -L"E:\Qt\Qt5.3.2\5.3\mingw482_32\lib" -lqwtd
} else {
    LIBS += -L"E:\Qt\Qt5.3.2\5.3\mingw482_32\lib" -lqwt
}

INCLUDEPATH += E:\Qt\Qt5.3.2\5.3\mingw482_32\include\Qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = intelligent
TEMPLATE = app

#ICON +=



include(SerialPort/SerialPort.pri)
include(MainWindow/MainWindow.pri)
include(StatueDialog/StatueDialog.pri)
include(AirDialog/AirDialog.pri)
include(misc/timer/TimeDialog.pri)
include(PowerDialog/PowerDialog.pri)



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





