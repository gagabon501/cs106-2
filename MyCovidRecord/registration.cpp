#include "registration.h"
#include "ui_registration.h"
#include <dbmanager.h>

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
        db.userRegister(ui->lineEdit_email->text(),ui->lineEdit_password->text(),ui->lineEdit_lastname->text(),ui->lineEdit_firstname->text(),ui->lineEdit_phone->text(),
                        ui->lineEdit_gender->text(),ui->lineEdit_nhi->text(),1,"",ui->lineEdit_dob->text());
        db.dbClose();

    }
    else
    {
        qDebug() << "Database is not open!";
    }



   QApplication::quit();
}

