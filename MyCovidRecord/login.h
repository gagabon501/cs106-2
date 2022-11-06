#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "dashboard.h"
#include "registration.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_forgotPassword_clicked();

    void on_pushButton_Register_clicked();

private:
    Ui::Login *ui;
    Dashboard *dashboard;
    Registration *registration;
};

#endif // LOGIN_H
