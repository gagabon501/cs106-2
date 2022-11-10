#include "registration.h"
#include "ui_registration.h"

#include <QString>
#include <QCryptographicHash>
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
#include <QSqlQuery>

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


    QString email = ui->lineEdit_email->text();

    QString password = ui->lineEdit_password->text();
    QString hashed_password = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha224).toHex();

    QString lastname = ui->lineEdit_lastname->text();
    QString firstname = ui->lineEdit_firstname->text();
    QString phone = ui->lineEdit_phone->text();
    QString nhi = ui->lineEdit_nhi->text();
    QString vaccine_status="no status";
    int level = 1;

//    QString dob = ui->comboBox_year->currentText()+"-"+QString::number(ui->comboBox_month->currentIndex()+1)+"-"+ui->comboBox_day->currentText();
    QString dob = ui->dateEdit->date().toString("yyyy-MM-dd");
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

        if (ui->lineEdit_password->text()==ui->lineEdit_ReTypePassword->text()) {
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
                 qDebug() << "Query unsuccessful!";
            }
        } else {
            QMessageBox::information(this,"Info","Passwords do not match. Registration unsuccessful!") ;
        }
    }
    else
    {
        qDebug() << "Registration failed: email cannot be empty";
    }


    Registration::hide();

}

void Registration::on_lineEdit_ReTypePassword_editingFinished()
{
    if (ui->lineEdit_password->text() != ui->lineEdit_ReTypePassword->text()) {
        QMessageBox::information(this,"Info","Passwords do not match!") ;
    }
}

