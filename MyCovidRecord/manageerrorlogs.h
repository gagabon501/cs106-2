#ifndef MANAGEERRORLOGS_H
#define MANAGEERRORLOGS_H

#include <QDialog>

namespace Ui {
class ManageErrorLogs;
}

class ManageErrorLogs : public QDialog
{
    Q_OBJECT

public:
    explicit ManageErrorLogs(QWidget *parent = nullptr);
    ~ManageErrorLogs();

public slots:
    void onInfoPassed9(QString uemail);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ManageErrorLogs *ui;
};

#endif // MANAGEERRORLOGS_H
