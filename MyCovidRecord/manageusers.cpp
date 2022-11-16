#include "manageusers.h"
#include "ui_manageusers.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

ManageUsers::ManageUsers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManageUsers)
{
    ui->setupUi(this);
}

ManageUsers::~ManageUsers()
{
    delete ui;
}


ManageUsers::ManageUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageUsers)
{
    ui->setupUi(this);
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;
    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    query->prepare("SELECT * from manage_users");
    query->exec();

    //    model->setQuery(*query);
    model->setQuery(std::move(*query)); //to resolve the warning
    //

    ui->tableView->setModel(model);

}

void ManageUsers::~ManageUsers()
{
    delete ui;
}

void ManageUsers::onInfoPassed10(QString comments)
{

}



