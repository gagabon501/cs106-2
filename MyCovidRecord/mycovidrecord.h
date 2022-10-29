#ifndef MYCOVIDRECORD_H
#define MYCOVIDRECORD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MyCovidRecord; }
QT_END_NAMESPACE

class MyCovidRecord : public QMainWindow
{
    Q_OBJECT

public:
    MyCovidRecord(QWidget *parent = nullptr);
    ~MyCovidRecord();

private:
    Ui::MyCovidRecord *ui;
};
#endif // MYCOVIDRECORD_H
