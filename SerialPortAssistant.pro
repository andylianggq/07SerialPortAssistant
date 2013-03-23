#-------------------------------------------------
#
# Project created by QtCreator 2012-04-12T15:01:52
#
#-------------------------------------------------

QT       += core gui


TEMPLATE    = app
TARGET      = SerialPortAssistant
MOC_DIR     = .obj
RCC_DIR     = .obj
OBJECTS_DIR = .obj
UI_DIR      = .obj
DESTDIR     = bin

CONFIG += \
          warn_on \
          qt \
          thread


include(qextserialport/qextserialport.pri)
include(frm_mainwindow/frm_mainwindow.pri)
include(common/common.pri)

SOURCES += main.cpp

RESOURCES += \
    resource.qrc

RC_FILE = ico.rc

CODECFORTR = UTF-8
