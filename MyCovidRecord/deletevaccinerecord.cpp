#include "deletevaccinerecord.h"
#include "ui_deletevaccinerecord.h"
#include <QSqlQuery>
#include <QString>
#include <QCryptographicHash>
#include <QDebug>

deleteVaccineRecord::deleteVaccineRecord(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deleteVaccineRecord)
{
    ui->setupUi(this);
}

deleteVaccineRecord::~deleteVaccineRecord()
{
    delete ui;
}

