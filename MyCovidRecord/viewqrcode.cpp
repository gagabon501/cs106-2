#include "viewqrcode.h"
#include "ui_viewqrcode.h"
#include "user.h"

#include <QPainter>
#include <QSqlQuery>
#include <QString>

#include <QFileInfo>

ViewQrCode::ViewQrCode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewQrCode)
{
    ui->setupUi(this);
}

ViewQrCode::~ViewQrCode()
{
    delete ui;
}

void ViewQrCode::onInfoPassed9(QString uemail)
{
    User user(nullptr, uemail);

    QString qrData = uemail + "/" + user.firstname + " " + user.lastname + "/" + user.dob + "/" + user.vaccine_status;
    qrwidget = new QRWidget();
    qrwidget->setQRData(qrData); //will ge

    ui->label_name->setText(user.firstname+" "+user.lastname);
    bool fileExists = QFileInfo::exists("./CovidCertQRCode.png");
    if (fileExists) {
        ui->label_qrcode->setGeometry(QRect(40, 60, 321, 191));
        ui->label_qrcode->setPixmap(QPixmap(QString::fromUtf8("./CovidCertQRCode.png")));

    }


}
