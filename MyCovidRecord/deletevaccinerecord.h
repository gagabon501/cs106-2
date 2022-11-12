#ifndef DELETEVACCINERECORD_H
#define DELETEVACCINERECORD_H

#include <QMainWindow>

namespace Ui {
class deleteVaccineRecord;
}

class deleteVaccineRecord : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteVaccineRecord(QWidget *parent = nullptr);
    ~deleteVaccineRecord();

private slots:
//    void on_searchUser_clicked();

private:
    Ui::deleteVaccineRecord *ui;
};

#endif // DELETEVACCINERECORD_H
