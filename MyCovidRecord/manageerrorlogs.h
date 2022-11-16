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


private slots:

    void on_pushButton_save_clicked();


    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::ManageErrorLogs *ui;
};

#endif // MANAGEERRORLOGS_H
