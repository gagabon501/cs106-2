#include "viewcovidtestresult.h"
#include "ui_viewcovidtestresult.h"
#include "user.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

QString resultEmail;

ViewCovidTestResult::ViewCovidTestResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewCovidTestResult)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

ViewCovidTestResult::~ViewCovidTestResult()
{
    delete ui;
}

void ViewCovidTestResult::onInfoPassed3(QString uemail)
{
    resultEmail = uemail;
    User user(nullptr,uemail);

    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;

    query->prepare("SELECT date_administered, time_administered, administered_by, test_type, test_result from covid_test where email='"+uemail+"'");
    query->exec();

//    model->setQuery(*query);
    model->setQuery(std::move(*query)); //to resolve the warning
//
    ui->label_result->setText("Covid test results for: "+user.firstname+" "+user.lastname);
    ui->tableView->setModel(model);


}

void ViewCovidTestResult::on_pushButton_clicked()
{
    this->close();
}

