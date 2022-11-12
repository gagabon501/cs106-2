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
//    void on_pushButton_3_customContextMenuRequested(const QPoint &pos); //Gil 7-11-22: had to remove this as this is causing an error - reference error since this does not have a corresponding function inside the UI.

//    void on_pushButton_4_clicked();

    void on_vaccineType_clicked();

    void on_searchUser_clicked();

private:
    Ui::CreateRecord *ui;
};

#endif // CREATERECORD_H
