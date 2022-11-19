#include "viewsystemlogs.h"
#include "ui_viewsystemlogs.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

ViewSystemLogs::ViewSystemLogs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewSystemLogs)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;

    query->prepare("SELECT * FROM system_logs");
    query->exec();

    model->setQuery(std::move(*query)); //to resolve the warning

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true); //hide id column

}

ViewSystemLogs::~ViewSystemLogs()
{
    delete ui;
}
