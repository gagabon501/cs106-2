#include "uploadrat.h"
#include "ui_uploadrat.h"
#include "user.h"

#include <QDebug>
#include <QDateTimeEdit>
#include <QString>
#include <QSqlQuery>

QString uEmail;

UploadRAT::UploadRAT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadRAT)
{
    ui->setupUi(this);
    ui->dateEdit_tested->setDate(QDate::currentDate());

}

UploadRAT::~UploadRAT()
{
    delete ui;
}




void UploadRAT::onInfoPassed2(QString uemail)
{
    uEmail = uemail;


}


void UploadRAT::on_buttonBox_accepted()
{
    User user(nullptr,uEmail); //when this object is instantiated, the query inside user.cpp is executed thus filling in all the properties (variables) in there.


    QString dateStr = ui->dateEdit_tested->date().toString("yyyy-MM-dd"), lastname, firstname, email, test_result = "Negative";
    qDebug() << dateStr;
    QSqlQuery queryAdd;

    lastname = user.lastname;
    firstname = user.firstname;


    if(ui->radioButton_C_Yes->isChecked() && ui->radioButton_T_Yes->isChecked())
    {
        test_result ="Positive";

    }

    queryAdd.prepare("INSERT INTO covid_test (email,date_entered, date_administered, administered_by, test_type, test_result) VALUES (:email,:date_entered,:date_administered,:administered_by,:test_type,:test_result);");
    queryAdd.bindValue(":email", uEmail);
    queryAdd.bindValue(":date_entered", dateStr);
    queryAdd.bindValue(":date_administered", dateStr);
    queryAdd.bindValue(":administered_by", firstname+" "+lastname);
    queryAdd.bindValue(":test_type", "RAT");
    queryAdd.bindValue(":test_result", test_result);

    if (queryAdd.exec())
    {
        qDebug() << "Upload RAT successful!";
    }
    else
    {
         qDebug() << "RAT upload unsuccessful!";
    }
}

