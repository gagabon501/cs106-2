#include "userrecords.h"
#include "ui_userrecords.h"
#include "user.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

UserRecords::UserRecords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserRecords)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

UserRecords::~UserRecords()
{
    delete ui;
}

void UserRecords::onInfoPassed8(QString email)
{

    User user(nullptr,email);

    //Display on the vaccine record part
    QString lastname, firstname, dob, gender, dose1, dose2, dose3, status, vaccine_name, manufacturer ;

    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT lastname, firstname, dob, gender, date_dose1, date_dose2, date_dose3, vaccine_status, vaccine_name, manufacturer FROM user WHERE email='"+email+"'");


    if (!query->exec()) QMessageBox::information(this,"Info","Error: "+query->lastError().text());
    else {
        int i = 0;
        while(query->next()) {
            i++;
            lastname = query->value(0).toString();
            firstname = query->value(1).toString();
            dob = query->value(2).toString();
            gender = query->value(3).toString();
            dose1 = query->value(4).toString();
            dose2 = query->value(5).toString();
            dose3 = query->value(6).toString();
            status = query->value(7).toString();
            vaccine_name = query->value(8).toString();
            manufacturer = query->value(9).toString();
        }

        if(i == 1) {
            ui->label_name->setText(firstname+" "+lastname);
            ui->lineEdit_dose1->setText(dose1);
            ui->lineEdit_dose2->setText(dose2);
            ui->lineEdit_dose3->setText(dose3);
            ui->lineEdit_manufacturer->setText(manufacturer);
            ui->lineEdit_vaccine_name->setText(vaccine_name);
            ui->lineEdit_status->setText(status);

        } else {
            QMessageBox::information(this,"Information","User not found in the database");
        }

      }

    //For the display of the RAT Test table
    QSqlQuery *qry = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;

    qry->prepare("SELECT * FROM covid_test WHERE email='"+email+"'");

    if(qry->exec()) {
        qDebug() << "Query successful!";

        model->setQuery(std::move(*qry)); //to resolve the warning
        ui->tableView->setModel(model);
        ui->tableView->setColumnHidden(0,true); //hide id column

    } else {
        qDebug() << "Query error: "+qry->lastError().text();
    };


}

void UserRecords::on_pushButton_clicked()
{
    this->close();
}

