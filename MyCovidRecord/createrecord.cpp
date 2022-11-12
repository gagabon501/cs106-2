#include "createrecord.h"
#include "ui_createrecord.h"

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




