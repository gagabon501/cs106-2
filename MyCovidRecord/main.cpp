#include "mycovidrecord.h"
#include "login.h"
#include "dashboard.h"
#include "updateprofile.h"
#include "uploadrat.h"
#include "viewcovidtestresult.h"

#include <QApplication>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Login w1;
    Dashboard w2;
    UpdateProfile w3;
    UploadRAT w4;
    ViewCovidTestResult w5;

    QObject::connect(&w1,SIGNAL(Info_Collected(QString)),&w2,SLOT(onInfoPassed(QString)));

    QObject::connect(&w1,SIGNAL(Info_Collected(QString)),&w3,SLOT(onInfoPassed1(QString)));

    QObject::connect(&w1,SIGNAL(Info_Collected(QString)),&w4,SLOT(onInfoPassed2(QString)));

    QObject::connect(&w1,SIGNAL(Info_Collected(QString)),&w5,SLOT(onInfoPassed3(QString)));

    MyCovidRecord w;
    w.show();
    w.setFixedSize(w.size());
    return a.exec();
}
