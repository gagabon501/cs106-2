#ifndef CREATERECORD_H
#define CREATERECORD_H

#include <QMainWindow>

namespace Ui {
class CreateRecord;
}

class CreateRecord : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateRecord(QWidget *parent = nullptr);
    ~CreateRecord();

private slots:




    void on_searchUser_clicked();

    void on_vaccineType_clicked();

    void on_createRecord_clicked();

private:
    Ui::CreateRecord *ui;
    CreateRecord *createrecord;
};

#endif // CREATERECORD_H
