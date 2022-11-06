#include "mycovidrecord.h"
#include "login.h"
#include "dashboard.h"

#include <QApplication>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Login w1;
    Dashboard w2;
    QObject::connect(&w1,SIGNAL(Info_Collected(QString)),&w2,SLOT(onInfoPassed(QString)));

    MyCovidRecord w;
    w.show();
    w.setFixedSize(w.size());
    return a.exec();
}
