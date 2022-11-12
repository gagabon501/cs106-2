#ifndef MANAGEDOCUMENTS_H
#define MANAGEDOCUMENTS_H

#include "createrecord.h"
#include "deletevaccinerecord.h"
#include "updatevaccinerecord.h"
#include <QMainWindow>

namespace Ui {
class manageDocuments;
}

class manageDocuments : public QMainWindow
{
    Q_OBJECT

public:
    explicit manageDocuments(QWidget *parent = nullptr);
    ~manageDocuments();

private slots:

    void on_CreateVacRec_clicked();

    void on_DeleteVacRec_clicked();

    void on_UpdateVacRec_clicked();

private:
    Ui::manageDocuments *ui;
    CreateRecord *createrecord;
    deleteVaccineRecord *deletevaccinerecord;
    UpdateVaccineRecord *updatevaccinerecord;
};

#endif // MANAGEDOCUMENTS_H
