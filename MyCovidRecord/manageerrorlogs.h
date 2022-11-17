#ifndef MANAGEERRORLOGS_H
#define MANAGEERRORLOGS_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class ManageErrorLogs;
}

class ManageErrorLogs : public QDialog
{
    Q_OBJECT

public:
    explicit ManageErrorLogs(QWidget *parent = nullptr);
    ~ManageErrorLogs();


private slots:


    void on_tableView_activated(const QModelIndex &index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::ManageErrorLogs *ui;
};

#endif // MANAGEERRORLOGS_H
