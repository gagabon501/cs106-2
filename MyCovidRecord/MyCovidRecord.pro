QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../MyCovidRecord/MyCovidRecord

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogin.cpp \
    changepassword.cpp \
    createrecord.cpp \
    dashboard.cpp \
    deletevaccinerecord.cpp \
    login.cpp \
    main.cpp \
    managedocuments.cpp \
    mycovidrecord.cpp \
    registration.cpp \
    updateprofile.cpp \
    updatevaccinerecord.cpp \
    user.cpp \
    viewcovidtestresult.cpp


HEADERS += \
    adminlogin.h \
    changepassword.h \
    createrecord.h \
    dashboard.h \
    deletevaccinerecord.h \
    login.h \
    managedocuments.h \
    mycovidrecord.h \
    registration.h \
    updateprofile.h \
    updatevaccinerecord.h \
    user.h \
    viewcovidtestresult.h

FORMS += \
    adminlogin.ui \
    changepassword.ui \
    createrecord.ui \
    dashboard.ui \
    deletevaccinerecord.ui \
    login.ui \
    managedocuments.ui \
    mycovidrecord.ui \
    registration.ui \
    updateprofile.ui \
    updatevaccinerecord.ui \
    viewcovidtestresult.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/mycovidrecord.qrc
