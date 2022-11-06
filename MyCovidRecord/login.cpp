#include "login.h"
#include "ui_login.h"

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>

#include <QString>
#include <QCryptographicHash>
#include <QDebug>
#include <QMessageBox>


QString dbname = "covid19.db";


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    connect(ui->pushButton,SIGNAL(clicked()),SLOT(on_pushButton_clicked()));

    QSqlDatabase n_db = QSqlDatabase::addDatabase("QSQLITE");

    n_db.setDatabaseName(dbname);

    if (!n_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok!";

    }


}

Login::~Login()
{
    delete ui;
   QSqlDatabase::removeDatabase(dbname);
}

//QString *Login::userEmail() {
//    return ui->lineEdit_username->text();
//}

void Login::on_pushButton_clicked()
{

    emit Info_Collected(ui->lineEdit_username->text());

    dashboard = new Dashboard;
    dashboard->onInfoPassed(ui->lineEdit_username->text());

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

                 dashboard->show();

             } else {
                 ui->label_ErrorMsg->setText("Wrong username or password: "+QString::number(count));
             }

         }
     } else {
          qDebug() << "Query unsuccessful!";
     }

     QSqlDatabase::removeDatabase(dbname);


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

