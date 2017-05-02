#-------------------------------------------------
#
# Project created by QtCreator 2016-03-07T16:37:02
#
#-------------------------------------------------

QT += core
QT += core gui
QT += serialport

DEFINES += QT_DLL QWT_DLL
LIBS += -L"E:\Qt\Qt5.3.2\5.3\mingw482_32\lib" -lqwtd
LIBS += -L"E:\Qt\Qt5.3.2\5.3\mingw482_32\lib" -lqwt
INCLUDEPATH += E:\Qt\Qt5.3.2\5.3\mingw482_32\include\Qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt8_2_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    time_dialog.cpp \
    light_window_dialog.cpp \
    dialogserial.cpp \
    air_dialog.cpp \
    read_thread.cpp \
    status_dialog.cpp \
    serial_data.cpp \
    power_dialog.cpp

HEADERS  += mainwindow.h \
    time_dialog.h \
    light_window_dialog.h \
    dialogserial.h \
    air_dialog.h \
    read_thread.h \
    status_dialog.h \
    commonhelper.h \
    serial_data.h \
    power_dialog.h \
    ui_power_dialog.h

FORMS    += mainwindow.ui \
    time_dialog.ui \
    light_window_dialog.ui \
    dialogserial.ui \
    air_dialog.ui \
    status_dialog.ui \
    power_dialog.ui

RESOURCES += \
    resource.qrc


DISTFILES += \
    新建文本文档.txt
####################### OPENCV ######################################

