#include "reporterror.h"
#include "ui_reporterror.h"
#include "user.h"

#include <QDebug>
#include <QDate>
#include <QString>
#include <QSqlQuery>

QString rEmail;

ReportError::ReportError(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportError)
{

    ui->setupUi(this);
    ui->label_dateReported->setText(QDate::currentDate().toString());
}

ReportError::~ReportError()
{
    delete ui;
}

void ReportError::onInfoPassed7(QString uemail)
{
  rEmail = uemail;
  User user(nullptr,rEmail); //when this object is instantiated, the query inside user.cpp is executed thus filling in all the properties (variables) in there.
  ui->label_reportedBy->setText("Reported by: "+user.firstname+ " "+user.lastname);
}

void ReportError::on_buttonBox_accepted()
{
    QString dateStr = QDate::currentDate().toString(), logDesc = ui->textEdit_description->toPlainText();
    int log_priority = 1;
    QSqlQuery queryAdd;

    queryAdd.prepare("INSERT INTO error_logs (email,date_entered,log_description,log_priority,log_status,actioned_by,remarks) VALUES (:email,:date_entered,:log_description,:log_priority,:log_status,:actioned_by,:remarks);");
    queryAdd.bindValue(":email", rEmail);
    queryAdd.bindValue(":date_entered", dateStr);
    queryAdd.bindValue(":log_description", logDesc);
    queryAdd.bindValue(":log_priority", log_priority);
    queryAdd.bindValue(":log_status", "Open");
    queryAdd.bindValue(":actioned_by", "TBA");
    queryAdd.bindValue(":remarks", "Open");

    if (queryAdd.exec())
    {
        qDebug() << "Upload Error successful!";
    }
    else
    {
         qDebug() << "Upload Error unsuccessful!";
    }

}

