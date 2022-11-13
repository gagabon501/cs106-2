#include "manageusers.h"
#include "ui_manageusers.h"

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
