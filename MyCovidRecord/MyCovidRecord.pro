QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../MyCovidRecord/MyCovidRecord

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dashboard.cpp \
    login.cpp \
    main.cpp \
    maindocuments.cpp \
    mycovidrecord.cpp \
    registration.cpp \
    dbmanager.cpp \
    user.cpp


HEADERS += \
    dashboard.h \
    login.h \
    maindocuments.h \
    mycovidrecord.h \
    registration.h \
    dbmanager.h \
    user.h

FORMS += \
    dashboard.ui \
    login.ui \
    maindocuments.ui \
    mycovidrecord.ui \
    registration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/mycovidrecord.qrc
