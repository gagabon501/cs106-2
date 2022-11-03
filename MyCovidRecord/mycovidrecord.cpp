#include "mycovidrecord.h"
#include "ui_mycovidrecord.h"
#include "login.h"
#include <QScreen>

MyCovidRecord::MyCovidRecord(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyCovidRecord)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center()); //center the form in the main window
//    this->showMaximized();
}

MyCovidRecord::~MyCovidRecord()
{
    delete ui;
}


void MyCovidRecord::on_pushButton_3_clicked()
{
    this->hide();
    registration = new Registration(this);
    registration->setFixedSize(registration->size());
    registration->show();
    this->show();
}


void MyCovidRecord::on_pushButton_clicked()
{
    this->hide();
    Login login(this);
    login.setModal(true);
    login.exec();
}

