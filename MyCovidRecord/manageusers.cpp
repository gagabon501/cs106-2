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
    ui->tableView->setColumnHidden(8,true); //hide vaccine_status column

    ui->tableView->setColumnHidden(10,true); //hide date_dose1 column
    ui->tableView->setColumnHidden(11,true); //hide date_dose2 column
    ui->tableView->setColumnHidden(12,true); //hide date_dose3 column
    ui->tableView->setColumnHidden(13,true); //hide vaccine_name column
    ui->tableView->setColumnHidden(14,true); //hide manufacturer column

    ui->tableView->setItemDelegateForColumn(0, new NotEditableDelegate(this)); //make the email column non-editable as this is a PRIMARY KEY
}


ManageUsers::~ManageUsers()
{
    delete ui;
}



void ManageUsers::on_updatUser_clicked()
{
    this->close();
}

