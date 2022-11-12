#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

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


private:
    Ui::AdminLogin *ui;
};

#endif // ADMINLOGIN_H
