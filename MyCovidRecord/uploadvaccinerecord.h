#ifndef UPLOADVACCINERECORD_H
#define UPLOADVACCINERECORD_H

#include <QDialog>

namespace Ui {
class UploadVaccineRecord;
}

class UploadVaccineRecord : public QDialog
{
    Q_OBJECT

public:
    explicit UploadVaccineRecord(QWidget *parent = nullptr);
    ~UploadVaccineRecord();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::UploadVaccineRecord *ui;
};

#endif // UPLOADVACCINERECORD_H
