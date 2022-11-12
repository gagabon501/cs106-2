#ifndef UPDATEVACCINERECORD_H
#define UPDATEVACCINERECORD_H

#include <QMainWindow>

namespace Ui {
class UpdateVaccineRecord;
}

class UpdateVaccineRecord : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpdateVaccineRecord(QWidget *parent = nullptr);
    ~UpdateVaccineRecord();

private:
    Ui::UpdateVaccineRecord *ui;
};

#endif // UPDATEVACCINERECORD_H
