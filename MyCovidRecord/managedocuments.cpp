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
