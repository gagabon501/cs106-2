#include "registration.h"
#include "ui_registration.h"
#include <dbmanager.h>
#include <QString>
#include <QCryptographicHash>
#include <QDebug>
#include <QStringList>

// Change to any path you wish
QString path = "covid19.db";

DbManager db(path);


Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    int i = 0;
    QStringList months;
    months = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    for(i = 1; i <= 31; i++) {
        ui->comboBox_day->addItem(QString::number(i));
    }
    for(int i=0;i<12;i++) {
        ui->comboBox_month->addItem(months[i]);
    }
    for(i=1940;i<=2022;i++) {
        ui->comboBox_year->addItem(QString::number(i));
    }

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


//        db.userRegister(ui->lineEdit_email->text(),hashed_password,ui->lineEdit_lastname->text(),ui->lineEdit_firstname->text(),ui->lineEdit_phone->text(),
//                        ui->lineEdit_gender->text(),ui->lineEdit_nhi->text(),1,"no status",ui->lineEdit_dob->text());

        QString dob = ui->comboBox_year->currentText()+"-"+QString::number(ui->comboBox_month->currentIndex()+1)+"-"+ui->comboBox_day->currentText();
        QString gender = "";
        if(ui->radioButton_female->isChecked()){
            gender = ui->radioButton_female->text();
        }
        if(ui->radioButton_male->isChecked()){
            gender = ui->radioButton_male->text();
        }
        if(ui->radioButton_other->isChecked()){
            gender = ui->radioButton_other->text();
        }

//        qDebug() << dob;
        db.userRegister(ui->lineEdit_email->text(),hashed_password,ui->lineEdit_lastname->text(),ui->lineEdit_firstname->text(),ui->lineEdit_phone->text(),
                                gender,ui->lineEdit_nhi->text(),1,"no status",dob);

//        db.userRegister(ui->lineEdit_email->text(),hashed_password,ui->lineEdit_lastname->text(),ui->lineEdit_firstname->text(),ui->lineEdit_phone->text(),
//                        ui->lineEdit_nhi->text(),1,"no status");

    }
    else
    {
        qDebug() << "Database is not open!";
    }
    Registration::hide();

}

