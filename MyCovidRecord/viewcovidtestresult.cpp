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
//    for (int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)
//    {
//        ui->tableView->horizontalHeader()->setSectionResizeMode(
//            c, QHeaderView::Stretch);
//    }

//    User user;

//    QSqlQuery *query = new QSqlQuery();
//    QSqlQueryModel *model = new QSqlQueryModel;

//    query->prepare("SELECT * from covid_test");
//    query->exec();
//    model->setQuery(*query);

//    ui->tableView->setModel(model);

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

    query->prepare("SELECT * from covid_test where email='"+uemail+"'");
    query->exec();
    model->setQuery(*query);

    ui->label_result->setText("Covid test results for: "+user.firstname+" "+user.lastname);
    ui->tableView->setModel(model);


}

void ViewCovidTestResult::on_pushButton_clicked()
{
    this->close();
}

