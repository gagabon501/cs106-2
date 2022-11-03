#include "mycovidrecord.h"

#include <QApplication>
#include <QDebug>

//#include <dbmanager.h>

// Change to any path you wish
//static const QString path = "covid19.db";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyCovidRecord w;
    w.show();
    w.setFixedSize(w.size());
    return a.exec();
}
