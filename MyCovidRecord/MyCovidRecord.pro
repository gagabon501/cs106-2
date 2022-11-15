QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../MyCovidRecord/MyCovidRecord

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lqrencode
#QRWidget.cpp \
SOURCES += \
    adminlogin.cpp \
    changepassword.cpp \
    createrecord.cpp \
    dashboard.cpp \
    deletevaccinerecord.cpp \
    gagqr.cpp \
    login.cpp \
    main.cpp \
    managedocuments.cpp \
    manageerrorlogs.cpp \
    manageusers.cpp \
    mycovidrecord.cpp \
    registration.cpp \
    reporterror.cpp \
    updateprofile.cpp \
    uploadselftest.cpp \
    updatevaccinerecord.cpp \
    user.cpp \
    userrecords.cpp \
    viewcovidtestresult.cpp \
    viewvaccinereport.cpp \
    QRWidget.cpp

#    QRWidget.hpp \
HEADERS += \
    adminlogin.h \
    changepassword.h \
    createrecord.h \
    dashboard.h \
    deletevaccinerecord.h \
    gagqr.h \
    login.h \
    managedocuments.h \
    manageerrorlogs.h \
    manageusers.h \
    mycovidrecord.h \
    qrencode.h \
    registration.h \
    reporterror.h \
    updateprofile.h \
    uploadselftest.h \
    updatevaccinerecord.h \
    user.h \
    userrecords.h \
    viewcovidtestresult.h \
    viewvaccinereport.h \
    QRWidget.hpp

FORMS += \
    adminlogin.ui \
    changepassword.ui \
    createrecord.ui \
    dashboard.ui \
    deletevaccinerecord.ui \
    gagqr.ui \
    login.ui \
    managedocuments.ui \
    manageerrorlogs.ui \
    manageusers.ui \
    mycovidrecord.ui \
    registration.ui \
    reporterror.ui \
    updateprofile.ui \
    uploadselftest.ui \
    updatevaccinerecord.ui \
    userrecords.ui \
    viewcovidtestresult.ui \
    viewvaccinereport.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/mycovidrecord.qrc

