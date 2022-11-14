#include "dashboard.h"
#include "ui_dashboard.h"
#include "user.h"

#include <QPainter>
#include <QDebug>

#include <QScreen>
#include <QMessageBox>
#include <QString>
#include <QDateTime>
#include <QByteArray>
#include <QPrinter>
#include <QTextDocument>

#include <QSqlQuery>

QString userEmail; //this variable is accessible within this file

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center()); //center the form in the main window
    this->setFixedSize(this->size());

//    QtQrCodeWidget *qrCodeWidget = new QtQrCodeWidget(this);
//    qrCodeWidget->setBackground(Qt::transparent);
////    qrCodeWidget->setData(windowTitle().toUtf8());
//    qrCodeWidget->setData("Gilberto Gabon");
//    qrCodeWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

////    addWidget(qrCodeWidget);
//    ui->centralwidget->layout()->addWidget(qrCodeWidget);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::onInfoPassed(QString uemail)
{
    userEmail = uemail; //userEmail gets filled-in here

    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd-MMM-yyyy");

    User user(nullptr,uemail); //when this object is instantiated, the query inside user.cpp is executed thus filling in all the properties (variables) in there.

    ui->label_userName->setText(user.firstname + " "+ user.lastname);
    ui->label_currentDate->setText(formattedTime);

}



void Dashboard::on_actionQuit_triggered()
{

    QApplication::quit();
}


void Dashboard::on_actionViewVaccinationRecord_triggered()
{

    viewvaccinereport = new ViewVaccineReport(this);
    viewvaccinereport->onInfoPassed6(userEmail);
    viewvaccinereport->show();
}


void Dashboard::on_actionView_RAT_Test_Record_triggered()
{

    viewcovidtestresult = new ViewCovidTestResult(this);
    viewcovidtestresult->onInfoPassed3(userEmail);
    viewcovidtestresult->show();

}


void Dashboard::on_actionDownload_COVID_19_Certificate_triggered()
{
    QMessageBox::information(this,"Info","Downloaded Covid-19 certificate. Refer to CovidCert.pdf.");
    QString name = "Gilberto Gabon", filename="CovidCert.pdf";
    QString dob = "1968-12-20";
    QString dateExpiryStr = "2023-02-01";
    QString html = "<h1>Covid19 Vaccination Certificate</h1><h3>Kia ora</h3><p>This card is your personal vaccine pass - an official record of your COVID-19 vaccination status.</p><p>My Vaccine Pass allows you to access places within Aotearoa New Zealand that require proof of your vaccination status.</p><p>Name: "+name+"</p>";
    QString html1 = "<p>Date of birth: "+dob+"</p><p>Expires on: "+dateExpiryStr+"</p>";
    QString html2 = "<h6>You may be asked to show photo ID.For use in Aotearoa New Zealand and for international travels.</h6>";
//    QString html3 = "<img src='qr.png' width='500px' height='500px' />";
    QString html3 = "<div><img src='qr-code.png' width='100' height='100' /></div>";
    QTextDocument document;
    document.setHtml(html+html1+html2+html3);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFileName(filename);
    printer.setOutputFormat(QPrinter::PdfFormat);
    document.print(&printer);
}


void Dashboard::on_actionReport_Issues_triggered()
{
    reporterror = new ReportError(this);
    reporterror->onInfoPassed7(userEmail);
    reporterror->show();
}


void Dashboard::on_actionUpdate_Profile_triggered()
{

    updateprofile = new UpdateProfile(this);
    updateprofile->onInfoPassed1(userEmail);
    updateprofile->show();
}


void Dashboard::on_actionChange_Password_triggered()
{
//     QMessageBox::information(this,"Info","Change password") ;
     changepassword = new ChangePassword(this);
     changepassword->onInfoPassed5(userEmail);
     changepassword->show();
}


void Dashboard::on_actionUpload_RAT_Test_triggered()
{
//     QMessageBox::information(this,"Info","Upload RAT") ;
    uploadselftest = new UploadSelfTest(this);
    uploadselftest->onInfoPassed2(userEmail);
    uploadselftest->show();
}


void Dashboard::on_pushButton_6_clicked()
{
//    QMessageBox::information(this,"Info","Generate QR Code");
    User user(nullptr,userEmail);
//    QString qrData = user.userEmail+"/"+user.firstname+" "+user.lastname+"/"+user.dob+"/"+user.vaccine_status;
//    qrwidget = new QRWidget();
//    qrwidget->setQRData(qrData);
//    qrwidget->show();

}

