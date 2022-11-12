#include "uploadselftest.h"
#include "ui_uploadselftest.h"
#include "user.h"

#include <QDebug>
#include <QDateTimeEdit>
#include <QString>
#include <QSqlQuery>

QString uEmail;

UploadSelfTest::UploadSelfTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadSelfTest)
{
    ui->setupUi(this);
    ui->dateEdit_taken->setDate(QDate::currentDate());
    ui->timeEdit_taken->setTime(QTime::currentTime());

}

UploadSelfTest::~UploadSelfTest()
{
    delete ui;
}

void UploadSelfTest::onInfoPassed2(QString uemail)
{
  uEmail = uemail;
}


void UploadSelfTest::on_buttonBox_accepted()
{

    User user(nullptr,uEmail); //when this object is instantiated, the query inside user.cpp is executed thus filling in all the properties (variables) in there.


    QString dateStr = ui->dateEdit_taken->date().toString("yyyy-MM-dd"), lastname, firstname, email, test_result = "Negative";
    QString timeStr = ui->timeEdit_taken->time().toString("HH:mm:ss");

    qDebug() << timeStr;

    QSqlQuery queryAdd;

    lastname = user.lastname;
    firstname = user.firstname;


    if(ui->radioButton_control_yes->isChecked() && ui->radioButton_test_yes->isChecked())
    {
        test_result ="Positive";

    }

    queryAdd.prepare("INSERT INTO covid_test (email,date_entered, date_administered, administered_by, test_type, test_result, time_administered) VALUES (:email,:date_entered,:date_administered,:administered_by,:test_type,:test_result,:time_administered);");
    queryAdd.bindValue(":email", uEmail);
    queryAdd.bindValue(":date_entered", dateStr);
    queryAdd.bindValue(":date_administered", dateStr);
    queryAdd.bindValue(":administered_by", firstname+" "+lastname);
    queryAdd.bindValue(":test_type", "RAT");
    queryAdd.bindValue(":test_result", test_result);
    queryAdd.bindValue(":time_administered", timeStr);

    if (queryAdd.exec())
    {
        qDebug() << "Upload RAT successful!";
    }
    else
    {
         qDebug() << "RAT upload unsuccessful!";
    }
}


void UploadSelfTest::on_buttonBox_rejected()
{
    this->close();
}
