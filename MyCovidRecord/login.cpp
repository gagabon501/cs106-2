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
     QString hashed_password = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha224).toHex();

     QSqlQuery query;

     query.prepare("SELECT email, password FROM user WHERE email='"+email +"'");

     if(query.exec())
     {

         int count = 0;
         while(query.next()) {
             count++;
             pw = query.value(1).toString();
         }


         if(count != 1) {
             ui->label_ErrorMsg->setText("Wrong username or password: "+QString::number(count));
         } else {
             if (pw == hashed_password) {

                 this->close();

                 emit Info_Collected(ui->lineEdit_username->text());

                 dashboard = new Dashboard;
                 dashboard->onInfoPassed(ui->lineEdit_username->text());
                 dashboard->show();

             } else {
                 ui->label_ErrorMsg->setText("Wrong username or password: "+QString::number(count));
             }

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
    registration = new Registration();
    registration->show();

    Login::show();

}

