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

    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;

//    query->prepare("SELECT * from covid_test where email='"+email+"'");
    query->prepare("SELECT date_administered, time_administered, administered_by, test_type, test_result from covid_test where email='"+email+"'");
    query->exec();

//    model->setQuery(*query);
    model->setQuery(std::move(*query)); //to resolve the warning
//
    ui->label_name->setText("Records for: "+user.firstname+" "+user.lastname);
    ui->tableView->setModel(model);

    QSqlQuery qry;
    QString date_dose1, date_dose2, date_dose3, manufacturer, vaccine_name;

    qry.prepare("SELECT date_dose1, date_dose2, date_dose3, manufacturer, vaccine_name FROM vaccine WHERE email='"+email +"'");

    if(qry.exec())
    {
        int count = 0;
        while(qry.next()) {
            count++;

            date_dose1 = qry.value(0).toString();
            date_dose2 = qry.value(1).toString();
            date_dose3 = qry.value(2).toString();
            manufacturer = qry.value(3).toString();
            vaccine_name = qry.value(4).toString();

        }

        if(count > 0) {
            ui->lineEdit_dose1->setText(date_dose1);
            ui->lineEdit_dose2->setText(date_dose2);
            ui->lineEdit_dose3->setText(date_dose3);
            ui->lineEdit_manufacturer->setText(manufacturer);
            ui->lineEdit_vaccine_name->setText(vaccine_name);
        } else {
            qDebug() << "No record found.";
        }

    } else {
         qDebug() << "Query unsuccessful!";
    }


}

void UserRecords::on_pushButton_clicked()
{
    this->close();
}

