#include "mycovidrecord.h"

#include <QApplication>
#include <QDebug>
#include <QString>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MyCovidRecord w;
    w.show();
    w.setFixedSize(w.size());
    return a.exec();
}
