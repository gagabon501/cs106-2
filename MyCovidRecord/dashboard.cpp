#include "dashboard.h"
#include "ui_dashboard.h"

#include <QScreen>
#include <QMessageBox>
#include <QString>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>


QString db_dashboard= "covid19.db";

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
//    this->showMaximized();


    QSqlDatabase n_db = QSqlDatabase::addDatabase("QSQLITE");


    n_db.setDatabaseName(db_dashboard);

    if (!n_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok!";

    }

    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center()); //center the form in the main window
}

Dashboard::~Dashboard()
{
    delete ui;
    QSqlDatabase::removeDatabase(db_dashboard);
}

void Dashboard::onInfoPassed(QString uemail)
{
    ui->label_userName->setText(uemail);

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

