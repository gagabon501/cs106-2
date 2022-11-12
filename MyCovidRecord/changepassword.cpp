#include "changepassword.h"
#include "ui_changepassword.h"
#include <QSqlQuery>
#include <QString>
#include <QCryptographicHash>
#include <QMessageBox>

ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::onInfoPassed5(QString uemail)
{
  //Since this is called inside User's dashboard, set the email field with the emiited email and do not allow edits
  ui->lineEdit_email->setText(uemail); //retrieved from the onInfoPassed5() slot
  ui->lineEdit_email->setEnabled(false); //do not allow edits anymore when called inside the user's dashboard

}


void ChangePassword::on_buttonBox_accepted()
{

    QSqlQuery query;


    QString u_email = ui->lineEdit_email->text(), password=ui->lineEdit_new_password->text();

    QString hashed_password = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha224).toHex();

    if (ui->lineEdit_new_password->text() == ui->lineEdit_retype_password->text()) {
        query.prepare("UPDATE user SET password='"+hashed_password+"' WHERE email='"+u_email+"'");

        if(query.exec())
        {
            qDebug() << "Update successful!";
        } else {
             qDebug() << "Query unsuccessful!";
        }

    } else {
        QMessageBox::information(this,"Info","Passwords do not match. Password not changed!") ;
    }

    this->close();

}


void ChangePassword::on_buttonBox_rejected()
{
    this->close();
}

