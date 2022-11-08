#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>

#include "dashboard.h"
#include "registration.h"
#include "changepassword.h"
#include "updateprofile.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:

    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void Info_Collected(QString uemail);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_forgotPassword_clicked();

    void on_pushButton_Register_clicked();


private:
    Ui::Login *ui;
    Dashboard *dashboard;
    Registration *registration;
    ChangePassword *changepassword;
    UpdateProfile *updateprofile;
};

#endif // LOGIN_H
