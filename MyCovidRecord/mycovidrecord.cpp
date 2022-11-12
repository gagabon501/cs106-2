#include "mycovidrecord.h"
#include "ui_mycovidrecord.h"

#include <QScreen>
#include <QString>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>

QString dbname = "covid19.db";
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

MyCovidRecord::MyCovidRecord(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyCovidRecord)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center()); //center the form in the main window
    this->setFixedSize(this->size());
    db.setDatabaseName(dbname);

    if (!db.open())
    {
        qDebug() << db.lastError();
        QMessageBox::information(this,"Info","Unable to open DATABASE") ;
    }
    else
    {
        qDebug() << "Database: connection ok!";
//        QMessageBox::information(this,"Info","Database connection ok!") ;
        ui->statusBar->showMessage("Connected to the database: "+db.databaseName());

    }

}

MyCovidRecord::~MyCovidRecord()
{
    delete ui;
    db.close();
}


void MyCovidRecord::on_pushButton_login_clicked()
{
    this->close();
    login = new Login(this);
    login->show();
}


void MyCovidRecord::on_pushButton_register_clicked()
{
    this->hide();
    registration = new Registration(this);
    registration->setFixedSize(registration->size());
    registration->show();
    this->show();
}

