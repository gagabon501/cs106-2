#include "uploadrat.h"
#include "ui_uploadrat.h"
#include <QDebug>
#include <QDateTimeEdit>
#include <QString>

UploadRAT::UploadRAT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadRAT)
{
    ui->setupUi(this);
}

UploadRAT::~UploadRAT()
{
    delete ui;
}






void UploadRAT::on_buttonBox_accepted()
{
    QString dateStr = ui->dateEdit->date().toString("yyyy-MM-dd");
    qDebug() << dateStr;
}

