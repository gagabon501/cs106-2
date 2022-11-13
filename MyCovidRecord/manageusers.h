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

private:
    Ui::ManageUsers *ui;
};

#endif // MANAGEUSERS_H
