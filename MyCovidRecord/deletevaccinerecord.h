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

private:
    Ui::deleteVaccineRecord *ui;
};

#endif // DELETEVACCINERECORD_H
