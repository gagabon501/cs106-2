#include "deletevaccinerecord.h"
#include "ui_deletevaccinerecord.h"

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
