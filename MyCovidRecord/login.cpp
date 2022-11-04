#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QString>
#include <QCryptographicHash>
#include <QDebug>
#include <QMessageBox>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
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
             ui->label_ErrorMsg->setText("Wrong username or password.");
         } else {
             this->close();
             dashboard = new Dashboard();
             dashboard->show();
         }
     } else {
          qDebug() << "Query unsuccessful!";
     }


}



void Login::on_pushButton_forgotPassword_clicked()
{
      QMessageBox::information(this,"Info","Forgot password!");
}


void Login::on_pushButton_Register_clicked()
{
//     QMessageBox::information(this,"Info","Register Now!");
//    Login::hide();
    registration = new Registration();
    registration->show();
    qDebug() << "Back to the future!";
    Login::show();

}

