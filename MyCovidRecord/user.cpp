#include "user.h"
#include <QString>

User::User(QObject *parent)
    : QObject{parent}
{
struct UserInfo {
    QString u_email, u_lname, u_fname;
};

}

//void setUserInfo(QString u_email, QString u_lname, QString u_fname)
//{
////    QString email,lastname,firstname;
////    email = u_email;
////    lastname = u_lname;
////    firstname = u_fname;

//};

