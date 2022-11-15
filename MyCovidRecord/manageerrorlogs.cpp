#include "manageerrorlogs.h"
#include "ui_manageerrorlogs.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

ManageErrorLogs::ManageErrorLogs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageErrorLogs)
{
    ui->setupUi(this);
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;
    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    query->prepare("SELECT * from error_logs");
    query->exec();

//    model->setQuery(*query);
    model->setQuery(std::move(*query)); //to resolve the warning
//

    ui->tableView->setModel(model);

}

ManageErrorLogs::~ManageErrorLogs()
{
    delete ui;
}

void ManageErrorLogs::onInfoPassed9(QString uemail)
{
//Not in use for the meantime

}

void ManageErrorLogs::on_buttonBox_accepted()
{
    this->close();
}


void ManageErrorLogs::on_buttonBox_rejected()
{
    this->close();
}

