#include "gagqr.h"
#include "ui_gagqr.h"
#include "user.h"

gagqr::gagqr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gagqr)
{
    ui->setupUi(this);
    User user(nullptr, "gag@gmail.com");
    QString qrData = user.userEmail + "/" + user.firstname + " " + user.lastname + "/" + user.dob + "/" + user.vaccine_status;
    qrwidget = new QRWidget(this);
    qrwidget->setQRData(qrData);
    qrwidget->show();
}

gagqr::~gagqr()
{
    delete ui;
}

void gagqr::on_pushButton_clicked()
{
    this->close();
}

