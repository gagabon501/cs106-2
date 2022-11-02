#include "dashboard.h"
#include "ui_dashboard.h"
#include <QScreen>

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
//    this->showMaximized();

    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center()); //center the form in the main window
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_actionQuit_triggered()
{
    QApplication::quit();
}

