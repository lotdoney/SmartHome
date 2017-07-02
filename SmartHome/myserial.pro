# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = myserial
DESTDIR = ./release
CONFIG += release
DEFINES += _WINDOWS QT_DLL QWT_DLL QT_WIDGETS_LIB QT_MULTIMEDIA_LIB QT_SERIALPORT_LIB QT_NETWORK_LIB QT_SCRIPT_LIB
INCLUDEPATH += . \
    ../../../../../Code/CV2.4.9/include \
    ../../../../../Code/CV2.4.9/include/opencv \
    ../../../../../Code/CV2.4.9/include/opencv2 \
    ./../../../Qt5.3.2/5.3/mingw482_32/include/Qwt \
    ./../../../../QT/QT5.6.0_MSCV/5.6/MSVC2015/include \
    ./../../../../QT/QT5.6.0_MSCV/5.6/MSVC2015/include/QtWidgets \
    ./../../../../QT/QT5.6.0_MSCV/5.6/MSVC2015/include/QtMultimedia \
    ./../../../../QT/QT5.6.0_MSCV/5.6/MSVC2015/include/QtGui \
    ./../../../../QT/QT5.6.0_MSCV/5.6/MSVC2015/include/QtANGLE \
    ./../../../../QT/QT5.6.0_MSCV/5.6/MSVC2015/include/QtSerialPort \
    ./../../../../QT/QT5.6.0_MSCV/5.6/MSVC2015/include/QtNetwork \
    ./../../../../QT/QT5.6.0_MSCV/5.6/MSVC2015/include/QtScript \
    ./../../../../QT/QT5.6.0_MSCV/5.6/MSVC2015/include/QtCore \
    ./release \
    ./../../../../QT/QT5.6.0_MSCV/5.6/MSVC2015/mkspecs/win32-msvc2015 \
    ./GeneratedFiles
LIBS += -L"../../../../../Code/CV2.4.9/lib/Release" \
    -L"../../../../Qt5.3.2/5.3/mingw482_32/lib" \
    -lshell32 \
    -lopencv_ml249 \
    -lopencv_calib3d249 \
    -lopencv_contrib249 \
    -lopencv_core249 \
    -lopencv_features2d249 \
    -lopencv_flann249 \
    -lopencv_gpu249 \
    -lopencv_highgui249 \
    -lopencv_imgproc249 \
    -lopencv_legacy249 \
    -lopencv_objdetect249 \
    -lopencv_ts249 \
    -lopencv_video249 \
    -lopencv_nonfree249 \
    -lopencv_ocl249 \
    -lopencv_photo249 \
    -lopencv_stitching249 \
    -lopencv_superres249 \
    -lopencv_videostab249
DEPENDPATH += .
MOC_DIR += release
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(myserial.pri)
