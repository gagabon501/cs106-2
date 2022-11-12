#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "user.h"
#include <QMessageBox>
#include <QScreen>
#include <QMessageBox>
#include <QString>
#include <QDateTime>


QString adminEmail;

AdminLogin::AdminLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);

    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center()); //center the form in the main window
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::onInfoPassed4(QString uemail)
{
    adminEmail = uemail;

    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd-MMM-yyyy");

    User user(nullptr,uemail); //when this object is instantiated, the query inside user.cpp is executed thus filling in all the properties (variables) in there.

    ui->label_name->setText(user.firstname + " "+ user.lastname);
    ui->label_date->setText(formattedTime);

}

