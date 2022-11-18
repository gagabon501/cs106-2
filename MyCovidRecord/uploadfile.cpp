#include "uploadfile.h"
#include "ui_uploadfile.h"
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

void UploadFile::on_buttonBox_accepted()
{
    if(ui->lineEdit_description->text().isEmpty()) {
        QMessageBox::information(this,"Information","Please fill-in descrioption");
        this->show();
    }

    else {
        QString fileName = QFileDialog::getOpenFileName(this,"Open file");

        QString dateUpload = QDate::currentDate().toString();
        QString email = "gag@gmail.com";
        QString uploaded_by ="gil@gmail.com";
        QString description = ui->lineEdit_description->text();

        qDebug() << fileName;
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) return;
        QByteArray byteArray = file.readAll();

        QSqlQuery query;
//        query.prepare("INSERT INTO user_docs (email,filename,description,date_uploaded,file_contents,uploaded_by) VALUES (:email,:fileName,:description,:dateUpload,:byteArray,uploaded_by)");
        query.prepare("INSERT INTO user_docs (email,filename,description,date_uploaded,file_contents,uploaded_by) VALUES (?,?,?,?,?,?)");
        query.addBindValue(email);
        query.addBindValue(fileName);
        query.addBindValue(description);
        query.addBindValue(dateUpload);
        query.addBindValue(byteArray);
        query.addBindValue(uploaded_by);

        if(query.exec()) {
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



