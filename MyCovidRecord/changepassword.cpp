#include "changepassword.h"
#include "ui_changepassword.h"
#include <QSqlQuery>
#include <QString>
#include <QCryptographicHash>

ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_pushButton_clicked()
{
    QSqlQuery query;
    QString u_email = ui->lineEdit_email->text(), password=ui->lineEdit_new_password->text();

    QString hashed_password = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha224).toHex();

//    qDebug() << u_email << " " << password << " " << hashed_password;

    query.prepare("UPDATE user SET password='"+hashed_password+"' WHERE email='"+u_email+"'");

    if(query.exec())
    {
        qDebug() << "Update successful!";
    } else {
         qDebug() << "Query unsuccessful!";
    }

    ChangePassword::hide();
}

