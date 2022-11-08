#include "updateprofile.h"
#include "ui_updateprofile.h"
#include "user.h"

UpdateProfile::UpdateProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateProfile)
{
    ui->setupUi(this);

    //Pre-fill the Combo Box
    int i = 0;
    QStringList months;
    months = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    for(i = 1; i <= 31; i++) {
        ui->comboBox_day->addItem(QString::number(i));
    }
    for(int i=0;i<12;i++) {
        ui->comboBox_month->addItem(months[i]);
    }
    for(i=1940;i<=2022;i++) {
        ui->comboBox_year->addItem(QString::number(i));
    }

}

UpdateProfile::~UpdateProfile()
{
    delete ui;
}

void UpdateProfile::onInfoPassed1(QString uemail)
{


    User user(nullptr,uemail); //when this object is instantiated, the query inside user.cpp is executed thus filling in all the properties (variables) in there.

    //fill-in the lineEdit widgets with values from the user object
    ui->lineEdit_firstname->setText(user.firstname);
    ui->lineEdit_lastname->setText(user.lastname);
    ui->lineEdit_phone->setText(user.phone);
    ui->lineEdit_nhi->setText(user.nhi);
//    qDebug() << user.gender;
    qDebug() << user.dob;
    if(user.gender == "Female"){

       ui->radioButton_female->setChecked(true);
    }
    if(user.gender == "Male"){
       ui->radioButton_male->setChecked(true);
    }
    if(user.gender == "Other"){
       ui->radioButton_other->setChecked(true);
    }


//    qDebug() << "hey " << user.lastname;

//    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();

}
