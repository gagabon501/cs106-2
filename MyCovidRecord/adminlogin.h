#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H
#include "managedocuments.h"

#include <QMainWindow>

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

public slots:
    void onInfoPassed4(QString uemail);

private slots:


    void on_actionQuit_3_triggered();

    void on_actionManage_Documents_triggered();

private:
    Ui::AdminLogin *ui;
    manageDocuments *managedocuments;
};

#endif // ADMINLOGIN_H
