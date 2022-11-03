#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
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
     QString password = ui->lineEdit_password->text(), email = ui->lineEdit_username->text();
     QByteArray hashed_password = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha224).toHex();
     QSqlQuery query;
     if(query.exec("SELECT * FROM user WHERE email='"+email +"' and password='"+hashed_password +"'"))
     {
         int count = 0;
         while(query.next()) {
             count++;
         }

         if(count != 1) {
             ui->label_Status->setText("Wrong username or password: "+QString::number(count));
         } else {
             this->close();
             dashboard = new Dashboard();
             dashboard->show();
             this->show();
         }
     } else {
          qDebug() << "Query unsuccessful!";
     }

}

