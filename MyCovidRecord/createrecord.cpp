#include "createrecord.h"
#include "ui_createrecord.h"
#include "user.h"
#include <QSqlQuery>
#include <QString>
#include <QCryptographicHash>
#include <QDebug>


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


void CreateRecord::on_searchUser_clicked()
{

}


void CreateRecord::on_vaccineType_clicked()
{

}

