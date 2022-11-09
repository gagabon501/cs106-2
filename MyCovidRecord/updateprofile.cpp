#include "updateprofile.h"
#include "ui_updateprofile.h"
#include "user.h"
#include <QSqlQuery>
#include <QString>
#include <QDateTimeEdit>

QString username; //This is the trick to get the username/email be available to all the other functions in this form. The value for this is set during call of the SIGNAL (e.g. onInfoPassed1(QString uemail))

UpdateProfile::UpdateProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateProfile)
{
    ui->setupUi(this);

    //Pre-fill the Combo Box
//    int i = 0;
//    QStringList months;
//    months = {"January","February","March","April","May","June","July","August","September","October","November","December"};
//    for(i = 1; i <= 31; i++) {
//        ui->comboBox_day->addItem(QString::number(i));
//    }
//    for(int i=0;i<12;i++) {
//        ui->comboBox_month->addItem(months[i]);
//    }
//    for(i=1940;i<=2022;i++) {
//        ui->comboBox_year->addItem(QString::number(i));
//    }

}

UpdateProfile::~UpdateProfile()
{
    delete ui;
}

void UpdateProfile::onInfoPassed1(QString uemail)
{

//    QStringList months;
//    months = {"January","February","March","April","May","June","July","August","September","October","November","December"};

    User user(nullptr,uemail); //when this object is instantiated, the query inside user.cpp is executed thus filling in all the properties (variables) in there.

    username = uemail;

//    QString year, month, day, dob;
//    QStringList u_dob;
//    dob = user.dob;
//    u_dob = dob.split("-");

//    year = u_dob[0];
//    month = u_dob[1];
//    day = u_dob[2];

//    int num = month.toInt();


//    qDebug() << u_dob << year+month+day;

    QString date_string_on_db = user.dob;
    QDate Date = QDate::fromString(date_string_on_db,"yyyy-MM-dd");
    qDebug() << "from Db: " << Date;


    //fill-in the lineEdit widgets with values from the user object
    ui->lineEdit_firstname->setText(user.firstname);
    ui->lineEdit_lastname->setText(user.lastname);
    ui->lineEdit_phone->setText(user.phone);
    ui->lineEdit_nhi->setText(user.nhi);
    ui->dateEdit->setDate(Date);

//    qDebug() << user.dob;
    if(user.gender == "Female"){

       ui->radioButton_female->setChecked(true);
    }
    if(user.gender == "Male"){
       ui->radioButton_male->setChecked(true);
    }
    if(user.gender == "Other"){
       ui->radioButton_other->setChecked(true);
    }

//    ui->comboBox_day->setCurrentText(day);
//    ui->comboBox_month->setCurrentText(months[num-1]);
//    ui->comboBox_year->setCurrentText(year);

}

void UpdateProfile::on_buttonBox_accepted()
{
    QSqlQuery query;

    QString lastname, firstname, gender, phone, nhi;
//    QString dob = ui->comboBox_year->currentText()+"-"+QString::number(ui->comboBox_month->currentIndex()+1)+"-"+ui->comboBox_day->currentText();
     QString dob = ui->dateEdit->date().toString("yyyy-MM-dd");

    lastname = ui->lineEdit_lastname->text();
    firstname =ui->lineEdit_firstname->text();
    if(ui->radioButton_female->isChecked()){
        gender = ui->radioButton_female->text();
    }
    if(ui->radioButton_male->isChecked()){
        gender = ui->radioButton_male->text();
    }
    if(ui->radioButton_other->isChecked()){
        gender = ui->radioButton_other->text();
    }
    phone = ui->lineEdit_phone->text();
    nhi = ui->lineEdit_nhi->text();


    query.prepare("UPDATE user SET dob='"+dob+"', lastname='"+lastname+"', firstname='"+firstname+"', gender='"+gender+"', phone='"+phone+"', nhi='"+nhi+"' WHERE email='"+username+"'");

    if(query.exec())
    {
        qDebug() << "Update successful!" << username << dob;

    } else {
         qDebug() << "Query unsuccessful!";
    }

}


void UpdateProfile::on_buttonBox_rejected()
{
    this->close();
}

