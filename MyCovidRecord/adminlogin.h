#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H
#include "managedocuments.h"
#include "manageusers.h"
#include "manageerrorlogs.h"
#include "uploadfile.h"
#include "uploadvaccinerecord.h"
#include "viewsystemlogs.h"

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

    void on_actionManage_Users_triggered();

    void on_actionManage_Errors_triggered();

//    void on_pushButton_info_clicked();

    void on_actionUpload_Documents_triggered();

    void on_actionUpdate_Vaccine_Record_triggered();

    void on_actionView_System_Log_2_triggered();

private:
    Ui::AdminLogin *ui;
    manageDocuments *managedocuments;
    ManageUsers *manageusers;
    ManageErrorLogs *manageerrorlogs;
    UploadFile *uploadfile;
    UploadVaccineRecord *uploadvaccine;
    ViewSystemLogs *viewsystemlogs;
};

#endif // ADMINLOGIN_H
