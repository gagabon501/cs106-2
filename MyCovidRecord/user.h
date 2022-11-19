#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr, QString email="");

    QString userEmail;
    QString lastname;
    QString firstname;
    QString phone;
    QString gender;
    QString dob;
    QString nhi;
    QString vaccine_status;
    int level;
    bool userExists;

signals:

};

#endif // USER_H
