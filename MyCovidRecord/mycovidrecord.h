#ifndef MYCOVIDRECORD_H
#define MYCOVIDRECORD_H

#include <QMainWindow>
#include "registration.h"

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

private:
    Ui::MyCovidRecord *ui;
    Registration *registration;
};
#endif // MYCOVIDRECORD_H
