#ifndef MANAGEUSERS_H
#define MANAGEUSERS_H

#include <QMainWindow>

namespace Ui {
class ManageUsers;
}

class ManageUsers : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageUsers(QWidget *parent = nullptr);
    ~ManageUsers();

public slots:
    void onInfoPassed10(QString uemail);

private slots:
    void on_updatUser_accepted();

    void on_updatUser_rejected();

private:
    Ui::ManageUsers *ui;
};

#endif // MANAGEUSERS_H
