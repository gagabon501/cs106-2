#include "updatevaccinerecord.h"
#include "ui_updatevaccinerecord.h"

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
