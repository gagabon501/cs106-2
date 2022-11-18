#include "manageusers.h"
#include "ui_manageusers.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QScreen>

ManageUsers::ManageUsers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManageUsers)
{
    ui->setupUi(this);

    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center()); //center the form in the main window

    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("user");
    model->select();

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

