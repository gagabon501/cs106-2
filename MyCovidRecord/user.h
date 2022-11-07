#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);

//    void setUserInfo(QString u_email, QString u_lname, QString u_fname);

signals:

};

#endif // USER_H
