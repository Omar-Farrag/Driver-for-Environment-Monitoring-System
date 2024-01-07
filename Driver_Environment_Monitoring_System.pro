QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CurrentRecord.cpp \
    GUIDelegateThread.cpp \
    LogFileManager.cpp \
    LoggerThread.cpp \
    ProcessThresholds.cpp \
    ProcessorThread.cpp \
    SerialDelegate.cpp \
    StartStopper.cpp \
    WarningSignaller.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CurrentRecord.h \
    GUIDelegateThread.h \
    LogFileManager.h \
    LoggerThread.h \
    ProcessThresholds.h \
    ProcessorThread.h \
    SerialDelegate.h \
    StartStopper.h \
    WarningSignaller.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
