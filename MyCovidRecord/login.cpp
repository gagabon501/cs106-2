#include "login.h"
#include "ui_login.h"
#include "user.h"

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

//    connect(ui->pushButton,SIGNAL(clicked()),SLOT(on_pushButton_clicked())); //this causes another Dashboard form to be created. There is actually no need for this since in main.cpp
//                                                                               both Login (signal - event emitter) and Dashboard (slot - event receiver) have already been connected

}

Login::~Login()
{
    delete ui;

}


void Login::on_pushButton_clicked()
{

     QString password = ui->lineEdit_password->text(), email = ui->lineEdit_username->text(), pw;

     QString hashed_password = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha224).toHex(); //hash the entered password before comparing with hashed password from the database

     QSqlQuery query;

     query.prepare("SELECT email, password FROM user WHERE email='"+email+"' and password='"+hashed_password+"'");

     if(query.exec())
     {

         int count = 0;
         while(query.next()) {
             count++;
             pw = query.value(1).toString();
         }

         if (count != 1) {
              ui->label_ErrorMsg->setText("Wrong username or password: ");
         } else {
              this->close();

             User user(nullptr,ui->lineEdit_username->text());

             emit Info_Collected(ui->lineEdit_username->text());

             qDebug() << "User level: " << user.level;

             if (user.level > 1) {
                 adminlogin = new AdminLogin(this);
                 adminlogin->onInfoPassed4(ui->lineEdit_username->text());
                 adminlogin->show();

             } else {
                 dashboard = new Dashboard(this);
                 dashboard->onInfoPassed(ui->lineEdit_username->text());
                 dashboard->show();

             }


         }

     } else {
          qDebug() << "Query unsuccessful!";
     }

}


void Login::on_pushButton_forgotPassword_clicked()
{

    changepassword = new ChangePassword(this);
    changepassword->show();
    changepassword->setFixedSize(changepassword->size());
    Login::show();
}


void Login::on_pushButton_Register_clicked()
{
    registration = new Registration(this);
    registration->show();

    Login::show();

}

