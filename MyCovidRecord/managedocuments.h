#ifndef MANAGEDOCUMENTS_H
#define MANAGEDOCUMENTS_H

#include "createrecord.h"
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

private:
    Ui::manageDocuments *ui;
    CreateRecord *createrecord;
};

#endif // MANAGEDOCUMENTS_H
