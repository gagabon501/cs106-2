#include "viewvaccinereport.h"
#include "ui_viewvaccinereport.h"
#include "user.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

//QString resultEmail;


ViewVaccineReport::ViewVaccineReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewVaccineReport)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

ViewVaccineReport::~ViewVaccineReport()
{
    delete ui;
}

void ViewVaccineReport::onInfoPassed6(QString uemail)
{

    User user(nullptr,uemail);

    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;

    query->prepare("SELECT * from vaccine where email='"+uemail+"'");
    query->exec();


    model->setQuery(std::move(*query)); //to resolve the warning

    ui->label_name->setText("Covid-19 Vaccine Record for: "+user.firstname+" "+user.lastname);
    ui->tableView->setModel(model);


}

void ViewVaccineReport::on_pushButton_clicked()
{
    this->close();
}

