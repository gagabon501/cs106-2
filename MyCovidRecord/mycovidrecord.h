#ifndef MYCOVIDRECORD_H
#define MYCOVIDRECORD_H

#include <QMainWindow>
#include "registration.h"
#include "dashboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyCovidRecord; }
QT_END_NAMESPACE

class MyCovidRecord : public QMainWindow
{
    Q_OBJECT

public:
    MyCovidRecord(QWidget *parent = nullptr);
    ~MyCovidRecord();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MyCovidRecord *ui;
    Registration *registration;
    Dashboard *dashboard;
};
#endif // MYCOVIDRECORD_H
