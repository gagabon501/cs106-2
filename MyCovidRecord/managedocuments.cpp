#include "managedocuments.h"
#include "ui_managedocuments.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QByteArray>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

manageDocuments::manageDocuments(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manageDocuments)
{
    ui->setupUi(this);
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;
    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    query->prepare("SELECT * from user_docs");
    query->exec();

    //    model->setQuery(*query);
    model->setQuery(std::move(*query)); //to resolve the warning
    //

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true); //hide id column
    ui->tableView->setColumnHidden(5,true); //hide id column

}

manageDocuments::~manageDocuments()
{
    delete ui;
}


void manageDocuments::on_updatUser_clicked()
{
    this->close();

}


void manageDocuments::on_tableView_activated(const QModelIndex &index)
{
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString(); //id



    QSqlQuery *query = new QSqlQuery();
    if( !query->exec( "SELECT filename, file_contents from user_docs where id='"+id+"'" ))
            qDebug() << "Error getting image from table:\n" << query->lastError();
    query->first();

//    QString outFileName = query->value(0).toString();
    QString outFileName = QFileDialog::getSaveFileName(this,"Save As");

    QFile file(outFileName);
    if (!file.open(QFile::WriteOnly)) {  // was | QFile::Text))
        qDebug() << "Unable to open file.";
    } else {
        QByteArray outByteArray = query->value(1).toByteArray();
        file.write(outByteArray);
        qDebug() << "Downloaded: " << outFileName;

    }




}

