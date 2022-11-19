#include "uploadfile.h"
#include "ui_uploadfile.h"
#include "systemlog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QSqlQuery>
#include <QByteArray>
#include <QDateTimeEdit>
#include <QSqlError>

QString uploadEmail;

UploadFile::UploadFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadFile)
{
    ui->setupUi(this);
}

UploadFile::~UploadFile()
{
    delete ui;
}

void UploadFile::onInfoPassed10(QString uemail) {
    uploadEmail = uemail;
}

void UploadFile::on_buttonBox_accepted()
{
    if(ui->lineEdit_description->text().isEmpty()) {
        QMessageBox::information(this,"Information","Please fill-in descrioption");
        this->show();
    }

    else {
        QString fileName = QFileDialog::getOpenFileName(this,"Open file");

        QString dateUpload = QDate::currentDate().toString();
        QString email = ui->lineEdit_email->text();
        QString uploaded_by = uploadEmail;
        QString description = ui->lineEdit_description->text();

        qDebug() << fileName;
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) return;
        QByteArray byteArray = file.readAll();

        QSqlQuery query;
//        query.prepare("INSERT INTO user_docs (email,filename,description,date_uploaded,file_contents,uploaded_by) VALUES (:email,:fileName,:description,:dateUpload,:byteArray,uploaded_by)");

        //This is a nice way to craft the query for adding a record
        query.prepare("INSERT INTO user_docs (email,filename,description,date_uploaded,file_contents,uploaded_by) VALUES (?,?,?,?,?,?)");
        query.addBindValue(email);
        query.addBindValue(fileName);
        query.addBindValue(description);
        query.addBindValue(dateUpload);
        query.addBindValue(byteArray);
        query.addBindValue(uploaded_by);

        if(query.exec()) {

            //Log to system
            SystemLog log(nullptr,email,"Upload Document","Successfully uploaded document: "+fileName);

            qDebug() << "Record added.";
        } else {
            qDebug() << "Error adding: " << query.lastError();
        };

        this->close();
    }
}


void UploadFile::on_buttonBox_rejected()
{
    this->close();
}



