#-------------------------------------------------
#
# Project created by QtCreator 2019-05-06T11:07:02
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CAEN_Normandy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    digitizer.cpp \
    digitizer_configuration.cpp \
    trigger_configuration.cpp \
    qcustomplot.cpp \
    about.cpp \
    daqthread.cpp \
    savefile.cpp

HEADERS  += mainwindow.h \
    digitizer_configuration.h \
    trigger_configuration.h \
    digitizervariables.h \
    errorcodes.h \
    qcustomplot.h \
    about.h \
    daqthread.h \
    digitizer.h \
    savefile.h

FORMS    += mainwindow.ui \
    trigger_configuration.ui \
    digitizer_configuration.ui \
    about.ui \
    savefile.ui

INCLUDEPATH += /home/adrian/CAEN/CAENDigitizer_2.12.0/include

unix:LIBS += $$quote(-L/home/adrian/CAEN/CAENDigitizer_2.12.0/lib/x86_64) -lCAENDigitizer

