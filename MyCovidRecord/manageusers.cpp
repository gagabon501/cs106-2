#include "manageusers.h"
#include "ui_manageusers.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>

ManageUsers::ManageUsers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManageUsers)
{
    ui->setupUi(this);
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("user");
    model->select();


//    QSqlQuery *query = new QSqlQuery();
//    QSqlQueryModel *model = new QSqlQueryModel;
    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

//    query->prepare("SELECT * from user");
//    query->exec();

//    //    model->setQuery(*query);
//    model->setQuery(std::move(*query)); //to resolve the warning
    //

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(1,true); //hide password column
}


ManageUsers::~ManageUsers()
{
    delete ui;
}



void ManageUsers::on_updatUser_clicked()
{
    this->close();
}

