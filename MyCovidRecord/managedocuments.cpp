#include "managedocuments.h"
#include "ui_managedocuments.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

manageDocuments::manageDocuments(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manageDocuments)
{
    ui->setupUi(this);
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;
    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    query->prepare("SELECT * from manage_docs");
    query->exec();

    //    model->setQuery(*query);
    model->setQuery(std::move(*query)); //to resolve the warning
    //

    ui->tableView->setModel(model);

}

manageDocuments::~manageDocuments()
{
    delete ui;
}


void manageDocuments::on_updatUser_clicked()
{

}

