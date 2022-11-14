#include "createrecord.h"
#include "ui_createrecord.h"
#include <QSqlQuery>
#include <QString>
#include <QtDebug>
#include <QMessageBox>



CreateRecord::CreateRecord(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateRecord)
{
    ui->setupUi(this);
}

CreateRecord::~CreateRecord()
{
    delete ui;
}


void CreateRecord::on_vaccineType_clicked()
{
    QMessageBox::information(this,"Info","CLick on the correct vaccine type.");
    QString name = "vaccine type";
}

