#include "mycovidrecord.h"
#include "ui_mycovidrecord.h"

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
    registration->show();
}

