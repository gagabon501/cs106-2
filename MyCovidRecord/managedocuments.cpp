#include "managedocuments.h"
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

void manageDocuments::on_pushButton_6_clicked()
{

}


void manageDocuments::on_CreateVaccineRecord_clicked()
{

}

