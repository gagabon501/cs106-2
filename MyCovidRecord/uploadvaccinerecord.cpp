#include "uploadvaccinerecord.h"
#include "ui_uploadvaccinerecord.h"

#include <QDebug>
#include <QDateTimeEdit>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

UploadVaccineRecord::UploadVaccineRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadVaccineRecord)
{
    ui->setupUi(this);

    ui->frame_status->hide(); //hide the whole section at the start and show it when it finds the record of the user. Cool hack!

    ui->comboBox->addItem("Completed");
    ui->comboBox->addItem("Unvaccinated");
    ui->comboBox->addItem("Partial");

    ui->dateEdit_dose1->setDate(QDate());
    ui->dateEdit_dose2->setDate(QDate());
    ui->dateEdit_dose3->setDate(QDate());
}

UploadVaccineRecord::~UploadVaccineRecord()
{
    delete ui;
}

void UploadVaccineRecord::on_pushButton_clicked()
{
    QString email = ui->lineEdit_email->text().toLower();

    QSqlQuery query;

    query.prepare("SELECT * FROM user WHERE email='"+email+"'");

    if(query.exec()) {
        int count = 0;
        while(query.next()) {
            count++;

            //start collecting the data while going throught the loop. I'm sure there is only one record for each user because the email address is a PRIMARY KEY
            ui->label_name->setText("Name: "+query.value(2).toString()+" "+query.value(3).toString());
            ui->label_dob->setText("DOB: "+query.value(9).toString());
            ui->label_gender->setText("Gender: "+query.value(5).toString());
            ui->dateEdit_dose1->setDate(QDate::fromString(query.value(10).toString(),"yyyy-MM-dd"));
            ui->dateEdit_dose2->setDate(QDate::fromString(query.value(11).toString(),"yyyy-MM-dd"));
            ui->dateEdit_dose3->setDate(QDate::fromString(query.value(12).toString(),"yyyy-MM-dd"));
            ui->lineEdit_vaccine_name->setText(query.value(13).toString());
            ui->lineEdit_manufacturer->setText(query.value(14).toString());
            ui->comboBox->setCurrentText(query.value(8).toString());
        }

        if (count != 1) {
           QMessageBox::information(this,"Information","User not found in the database.");
        } else {
            ui->frame_status->show(); //now that you found the record - time to show the whole frame!
        }
    } else {
        QMessageBox::critical(this,"Warning","Query unsuccessful: "+query.lastError().text());
    }


}


void UploadVaccineRecord::on_buttonBox_accepted()
{
    QString email = ui->lineEdit_email->text().toLower(); //to make sure that the search string is consistent with the data stored in the db and guarantees a find.

    //QDateEdit widget has a default value of 'January 1, 2000' -- this ensures that if user does not change the date, the data saved in the db is not "2000-01-01"
    QString dose1 = QDate::fromString(ui->dateEdit_dose1->text(),"yyyy-MM-dd").year() <= 2000 ? "" : ui->dateEdit_dose1->text();
    QString dose2 = QDate::fromString(ui->dateEdit_dose2->text(),"yyyy-MM-dd").year() <= 2000 ? "" : ui->dateEdit_dose2->text();
    QString dose3 = QDate::fromString(ui->dateEdit_dose3->text(),"yyyy-MM-dd").year() <= 2000 ? "" : ui->dateEdit_dose3->text();

    QString vaccine_name = ui->lineEdit_vaccine_name->text();
    QString manufacturer = ui->lineEdit_manufacturer->text();
    QString status = ui->comboBox->currentText();

    QSqlQuery query, msgQry;

    msgQry.prepare("INSERT INTO system_logs VALUES");

    query.prepare("UPDATE user SET date_dose1='"+dose1+"', date_dose2='"+dose2+"', date_dose3='"+dose3+"', vaccine_name='"+vaccine_name+"', manufacturer='"+manufacturer+"', vaccine_status='"+status+"' WHERE email='"+email+"'");

    if(query.exec())
    {

        QMessageBox::information(this,"Information","Record updated successfully.");

    } else {

        QMessageBox::critical(this,"Warning","Record not updated. "+query.lastError().text());
    }

}

