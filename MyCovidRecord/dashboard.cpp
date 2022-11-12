#include "dashboard.h"
#include "ui_dashboard.h"
#include "user.h"

#include <QScreen>
#include <QMessageBox>
#include <QString>
#include <QDateTime>
#include <QByteArray>


#include <QSqlQuery>

QString userEmail; //this variable is accessible within this file

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center()); //center the form in the main window
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
    QMessageBox::information(this,"Info","View Vaccination Record") ;
}


void Dashboard::on_actionView_RAT_Test_Record_triggered()
{
//    QMessageBox::information(this,"Info","View RAT Test Record") ;
    viewcovidtestresult = new ViewCovidTestResult(this);
    viewcovidtestresult->onInfoPassed3(userEmail);
    viewcovidtestresult->show();

}


void Dashboard::on_actionDownload_COVID_19_Certificate_triggered()
{
    QMessageBox::information(this,"Info","Download COVID-19 Vaccination Certificate") ;
}


void Dashboard::on_actionReport_Issues_triggered()
{
    QMessageBox::information(this,"Info","Report Issues") ;

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

