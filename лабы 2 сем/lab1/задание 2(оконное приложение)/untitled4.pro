QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    author.cpp \
    button.cpp \
    dialog.cpp \
    dialog1.cpp \
    main.cpp \
    mainwindow.cpp \
    task1.cpp \
    task2.cpp \
    task3.cpp \
    taskinfo.cpp

HEADERS += \
    author.h \
    button.h \
    dialog.h \
    dialog1.h \
    mainwindow.h \
    task1.h \
    task2.h \
    task3.h \
    taskinfo.h

FORMS += \
    author.ui \
    button.ui \
    dialog.ui \
    dialog1.ui \
    mainwindow.ui \
    task1.ui \
    task2.ui \
    task3.ui \
    taskinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
