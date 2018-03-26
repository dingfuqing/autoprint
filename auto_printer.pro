#-------------------------------------------------
#
# Project created by QtCreator 2018-02-22T13:08:26
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = auto_printer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    useradddialog.cpp \
    userdeletedialog.cpp \
    userlogindialog.cpp \
    usermodifydialog.cpp \
    databaseoperation.cpp \
    confirmdialog.cpp \
    systemmessagedialog.cpp \
    datamanagedialog.cpp \
    parasytemsetdialog.cpp \
    rfidlogdialog.cpp \
    colordatamanagedialog.cpp

HEADERS += \
        mainwindow.h \
    useradddialog.h \
    userdeletedialog.h \
    userlogindialog.h \
    usermodifydialog.h \
    databaseoperation.h \
    confirmdialog.h \
    globe.h \
    systemmessagedialog.h \
    systemmessagedialog.h \
    datamanagedialog.h \
    parasytemsetdialog.h \
    rfidlogdialog.h \
    colordatamanagedialog.h

FORMS += \
        mainwindow.ui \
    useradddialog.ui \
    userdeletedialog.ui \
    userlogindialog.ui \
    usermodifydialog.ui \
    confirmdialog.ui \
    systemmessagedialog.ui \
    datamanagedialog.ui \
    parasytemsetdialog.ui \
    rfidlogdialog.ui \
    colordatamanagedialog.ui
