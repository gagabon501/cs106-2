#ifndef MANAGEDOCUMENTS_H
#define MANAGEDOCUMENTS_H

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
    void on_pushButton_6_clicked();

    void on_CreateVaccineRecord_clicked();

private:
    Ui::manageDocuments *ui;
};

#endif // MANAGEDOCUMENTS_H
