#include "user.h"

/*------------------------------------------------------------------------------------------------
 * This Class will hold the User information based on the email address passed to the constructor.
 * This is a handy class that can be instantiated anytime you need to retrieve user information.
 * We will implement this model with other objects, i.e. Document and Error Log
 *-----------------------------------------------------------------------------------------------*/


User::User(QObject *parent, QString email)
    : QObject{parent}

{
    QSqlQuery query;

//    qDebug() << email;

    query.prepare("SELECT email, lastname, firstname, gender, dob, phone, nhi, vaccine_status, level FROM user WHERE email='"+email +"'");

    if(query.exec())
    {
        int count = 0;
        while(query.next()) {
            count++;

            userEmail = query.value(0).toString();
            lastname = query.value(1).toString();
            firstname = query.value(2).toString();
            gender = query.value(3).toString();
            dob = query.value(4).toString();
            phone = query.value(5).toString();
            nhi = query.value(6).toString();
            vaccine_status = query.value(7).toString();
            level = query.value(8).toString().toInt();

        }

        if(count == 0) {
            qDebug() << "No record found";
            userExists = false;
        } else {
            userExists = true;
        }
    } else {
         qDebug() << "Query unsuccessful!";
         userExists = false;
    }
}

