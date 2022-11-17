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

//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("error_logs");
//    model->select();


    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;

    query->prepare("SELECT * from error_logs");
    query->exec();

//    model->setQuery(*query); //deprecated function, hence the use of move()
    model->setQuery(std::move(*query));

    ui->tableView->setModel(model); //put the model into the view
//    ui->label_date_reported->setText(ui->tableView->model()->data())



    ui->tableView->setColumnHidden(0,true); //hide id column

    ui->comboBox_status->addItem("Open");
    ui->comboBox_status->addItem("Closed");
    ui->comboBox_status->addItem("Deferred");

}

ManageErrorLogs::~ManageErrorLogs()
{
    delete ui;
}



void ManageErrorLogs::on_tableView_activated(const QModelIndex &index)
{


    QString id = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString(); //id

    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT * from error_logs where id='"+id+"'");
    if (query->exec()) {
        while(query->next()) {
            ui->label_reported_by->setText("Reported by: "+query->value(1).toString());
            ui->label_date_reported->setText("Date reported: "+query->value(2).toString());
            ui->textEdit_description->setText(query->value(3).toString());
            ui->label_priority->setText("Priority: "+query->value(4).toString());
            ui->comboBox_status->setCurrentText(query->value(5).toString());
            ui->lineEdit_actioned_by->setText(query->value(6).toString());
            ui->textEdit_remarks->setText(query->value(7).toString());
            ui->label_id->setText(id);
        }

    } else {
        qDebug() << "Query error: " << query->lastError();
    }
}


void ManageErrorLogs::on_buttonBox_accepted()
{
    QSqlQuery *query = new QSqlQuery();
    QString id = ui->label_id->text();
    QString remarks = ui->textEdit_remarks->toPlainText();
    QString actioned_by = ui->lineEdit_actioned_by->text();
    QString status = ui->comboBox_status->currentText();
    qDebug() << status << id;

    query->prepare("UPDATE error_logs SET remarks='"+remarks+"', actioned_by='"+actioned_by+"', log_status='"+status+"' WHERE id='"+id+"'");
    if(query->exec()) {
        if(query->numRowsAffected() < 1) {
            qDebug() << "No rows updated.";

        } else {

            qDebug() << "Update successful";

        }

    } else {
        qDebug() << "Update error: " << query->lastError();
    }

    this->close();


}


void ManageErrorLogs::on_buttonBox_rejected()
{
    this->close();
}



