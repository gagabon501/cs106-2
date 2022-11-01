#include "mycovidrecord.h"
#include "ui_mycovidrecord.h"
#include "login.h"

MyCovidRecord::MyCovidRecord(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyCovidRecord)
{
    ui->setupUi(this);
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
    this->show();
}

