#include "viewvaccinereport.h"
#include "ui_viewvaccinereport.h"
#include "user.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlError>

#include <QPainter>
#include <QDebug>
#include <QScreen>

#include <QFileInfo>

//QString resultEmail;


ViewVaccineReport::ViewVaccineReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewVaccineReport)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

}

ViewVaccineReport::~ViewVaccineReport()
{
    delete ui;
}

void ViewVaccineReport::onInfoPassed6(QString uemail)
{

    User user(nullptr,uemail);

    QSqlQuery *query = new QSqlQuery();
    QString lastname, firstname, dob, gender, dose1, dose2, dose3, status, vaccine_name, manufacturer ;

    query->prepare("SELECT lastname, firstname, dob, gender, date_dose1, date_dose2, date_dose3, vaccine_status, vaccine_name, manufacturer FROM user WHERE email='"+uemail+"'");

    if (!query->exec()) QMessageBox::information(this,"Info","Error: "+query->lastError().text());
    else {
        int i = 0;
        while(query->next()) {
            i++;
            lastname = query->value(0).toString();
            firstname = query->value(1).toString();
            dob = query->value(2).toString();
            gender = query->value(3).toString();
            dose1 = query->value(4).toString();
            dose2 = query->value(5).toString();
            dose3 = query->value(6).toString();
            status = query->value(7).toString();
            vaccine_name = query->value(8).toString();
            manufacturer = query->value(9).toString();
        }

        if(i == 1) {

            QString qrData = uemail + "/" + firstname + " " + lastname + "/" + dob + "/" + status;
            qrwidget = new QRWidget();
            qrwidget->setQRData(qrData); //will generate the QR Code PNG file (CovidCertQRCode.png)

            bool fileExists = QFileInfo::exists("./CovidCertQRCode.png");
            if (fileExists) {
                ui->label_name_age_gender->setText("Name: "+firstname+" "+lastname+" "+"DOB: "+dob+" "+"Gender: "+gender);
                ui->label_dose1->setText("First dose: "+dose1);
                ui->label_dose2->setText("Second dose: "+dose2);
                ui->label_dose3->setText("Third dose: "+dose3);
                ui->label_status->setText("Vaccine status: "+status);
                ui->label_vaccine_info->setText("Vaccine name: "+vaccine_name+" Manufacturer: "+manufacturer);
//                imagelabel->setObjectName(QString::fromUtf8("imagelabel"));
//                      imagelabel->setGeometry(QRect(20, 10, 371, 311));
//                      imagelabel->setPixmap(QPixmap(QString::fromUtf8(":/liqi/kinect.png")));
                ui->label_qrcode->setGeometry(QRect(436, 200, 161, 131));
                ui->label_qrcode->setPixmap(QPixmap(QString::fromUtf8("./CovidCertQRCode.png")));
            }

        } else {
            QMessageBox::information(this,"Information","User not found in the database");
        }

    }

}

void ViewVaccineReport::on_pushButton_clicked()
{
    this->close();
}

