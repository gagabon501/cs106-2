#ifndef MYCOVIDRECORD_H
#define MYCOVIDRECORD_H

#include <QMainWindow>
#include <QtSql>
#include <QString>

#include "registration.h"
#include "dashboard.h"
#include "login.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MyCovidRecord; }
QT_END_NAMESPACE

class MyCovidRecord : public QMainWindow
{
    Q_OBJECT

public:
    MyCovidRecord(QWidget *parent = nullptr);
    ~MyCovidRecord();

private slots:

    void on_pushButton_login_clicked();

    void on_pushButton_register_clicked();

    void on_pushButton_admin_clicked();

private:
    Ui::MyCovidRecord *ui;
    Registration *registration;
    Dashboard *dashboard;
    Login *login;

};
#endif // MYCOVIDRECORD_H
