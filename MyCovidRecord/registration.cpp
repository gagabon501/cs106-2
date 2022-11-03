#include "registration.h"
#include "ui_registration.h"
#include <dbmanager.h>
#include <QString>
#include <QCryptographicHash>

// Change to any path you wish
static const QString path = "covid19.db";

DbManager db(path);


Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_Save_clicked()
{

    if (db.isOpen())
    {
        QString password = ui->lineEdit_password->text();
        QByteArray hashed_password = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha224).toHex();


        db.userRegister(ui->lineEdit_email->text(),hashed_password,ui->lineEdit_lastname->text(),ui->lineEdit_firstname->text(),ui->lineEdit_phone->text(),
                        ui->lineEdit_gender->text(),ui->lineEdit_nhi->text(),1,"no status",ui->lineEdit_dob->text());


        db.closeDb();

    }
    else
    {
        qDebug() << "Database is not open!";
    }
    this->close();


}

