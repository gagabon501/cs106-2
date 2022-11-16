#include "manageerrorlogs.h"
#include "ui_manageerrorlogs.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>


ManageErrorLogs::ManageErrorLogs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageErrorLogs)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->resizeColumnsToContents();

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("error_logs");
    model->select();

    ui->tableView->setModel(model);

}

ManageErrorLogs::~ManageErrorLogs()
{
    delete ui;
}



void ManageErrorLogs::on_pushButton_save_clicked()
{
    this->close();
}



void ManageErrorLogs::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    qDebug() << val;
}

