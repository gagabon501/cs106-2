#include "dashboard.h"
#include "ui_dashboard.h"
#include "user.h"

#include <QScreen>
#include <QMessageBox>
#include <QString>


#include <QSqlQuery>

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


    User user(nullptr,uemail); //when this object is instantiated, the query inside user.cpp is executed thus filling in all the properties (variables) in there.
    ui->label_userName->setText(user.firstname + " "+ user.lastname);

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
    QMessageBox::information(this,"Info","View RAT Test Record") ;
}


void Dashboard::on_actionUpload_RAT_Test_triggered()
{
    QMessageBox::information(this,"Info","Upload RAT Test Record") ;
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
     QMessageBox::information(this,"Info","Update Profile") ;
}


void Dashboard::on_actionChange_Password_triggered()
{
     QMessageBox::information(this,"Info","Change password") ;
}

