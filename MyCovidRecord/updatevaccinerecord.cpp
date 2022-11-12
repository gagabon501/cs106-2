#include "updatevaccinerecord.h"
#include "ui_updatevaccinerecord.h"
#include <QSqlQuery>
#include <QString>
#include <QCryptographicHash>
#include <QDebug>

UpdateVaccineRecord::UpdateVaccineRecord(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UpdateVaccineRecord)
{
    ui->setupUi(this);
}

UpdateVaccineRecord::~UpdateVaccineRecord()
{
    delete ui;
}
