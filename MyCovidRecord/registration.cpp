#include "registration.h"
#include "ui_registration.h"

#include <QString>
#include <QCryptographicHash>
#include <QDebug>
#include <QStringList>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>


QString db_register_name = "covid19.db";

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    QSqlDatabase db_register = QSqlDatabase::addDatabase("QSQLITE");
    db_register.setDatabaseName(db_register_name);

    if (!db_register.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok!";

    }

    ui->setupUi(this);

    //Pre-fill the Combo Box
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

    QSqlDatabase::removeDatabase(db_register_name);
}

void Registration::on_pushButton_Save_clicked()
{

    QString email = ui->lineEdit_email->text();

    QString password = ui->lineEdit_password->text();
    QString hashed_password = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha224).toHex();

    QString lastname = ui->lineEdit_lastname->text();
    QString firstname = ui->lineEdit_firstname->text();
    QString phone = ui->lineEdit_phone->text();
    QString nhi = ui->lineEdit_nhi->text();
    QString vaccine_status="no status";
    int level = 1;

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

    if (!email.isEmpty())
    {
        QSqlQuery queryAdd;

        queryAdd.prepare("INSERT INTO user (email,password,lastname,firstname,phone,gender,nhi,level,vaccine_status,dob) VALUES (:email,:hashed_password,:lastname,:firstname,:phone,:gender,:nhi,:level,:vaccine_status,:dob);");
        queryAdd.bindValue(":email", email);
        queryAdd.bindValue(":hashed_password", hashed_password);
        queryAdd.bindValue(":lastname", lastname);
        queryAdd.bindValue(":firstname", firstname);
        queryAdd.bindValue(":phone", phone);
        queryAdd.bindValue(":gender", gender);
        queryAdd.bindValue(":nhi", nhi);
        queryAdd.bindValue(":level", level);
        queryAdd.bindValue(":vaccine_status", vaccine_status);
        queryAdd.bindValue(":dob", dob);

        if (queryAdd.exec())
        {
            qDebug() << "Registration successful!";
        }
        else
        {
            qDebug() << "Registration error: " << queryAdd.lastError();
        }

           QSqlDatabase::removeDatabase(db_register_name);
    }
    else
    {
        qDebug() << "Registration failed: email cannot be empty";
    }


    Registration::hide();

}

