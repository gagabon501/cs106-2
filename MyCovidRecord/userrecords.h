#ifndef USERRECORDS_H
#define USERRECORDS_H

#include <QDialog>

namespace Ui {
class UserRecords;
}

class UserRecords : public QDialog
{
    Q_OBJECT

public:
    explicit UserRecords(QWidget *parent = nullptr);
    ~UserRecords();

public slots:
    void onInfoPassed8(QString uemail);

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserRecords *ui;
};

#endif // USERRECORDS_H
