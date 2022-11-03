#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QCryptographicHash>
#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{

    QString password = ui->lineEdit_password->text();
    QByteArray hashed_password = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha224).toHex();
    qDebug() << "hashed: " << hashed_password;
    //searh db, then get the stored hashed password, then compare with the hashed password
    this->close();
    dashboard = new Dashboard();
    dashboard->show();
    this->show();

}

