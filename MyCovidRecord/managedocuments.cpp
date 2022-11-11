#include "managedocuments.h"
#include "createrecord.h"
#include "ui_managedocuments.h"

manageDocuments::manageDocuments(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manageDocuments)
{
    ui->setupUi(this);
}

manageDocuments::~manageDocuments()
{
    delete ui;
}






void manageDocuments::on_CreateVacRec_clicked()
{
    this->close();
    createrecord = new CreateRecord(this);
    createrecord->show();
}

