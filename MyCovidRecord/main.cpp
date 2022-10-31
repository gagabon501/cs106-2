#include "mycovidrecord.h"

#include <QApplication>

#include <QDebug>
#include <dbmanager.h>

// Change to any path you wish
static const QString path = "covid19.db";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DbManager db(path);

    if (db.isOpen())
    {
        db.createTable(); // Creates tables used by the application if it doens't exist. Otherwise, it will use existing table.
        db.addPerson("gagabon501@yahoo.com","password","Gabon","Gilberto","123-4567","Male","1234556",4,"Unvaccinated");

    }
    else
    {
        qDebug() << "Database is not open!";
    }

    MyCovidRecord w;
    w.show();
    w.setFixedSize(w.size());
    return a.exec();
}
