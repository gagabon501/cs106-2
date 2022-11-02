#include "maindocuments.h"
#include "ui_maindocuments.h"

mainDocuments::mainDocuments(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainDocuments)
{
    ui->setupUi(this);
}

mainDocuments::~mainDocuments()
{
    delete ui;
}
