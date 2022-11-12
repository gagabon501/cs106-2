#ifndef DASHBOARD_H
#define DASHBOARD_H


#include <QMainWindow>
#include <QString>

#include "updateprofile.h"
#include "viewcovidtestresult.h"
#include "uploadselftest.h"
#include "changepassword.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

public slots:
    void onInfoPassed(QString uemail);

private slots:
    void on_actionQuit_triggered();

    void on_actionViewVaccinationRecord_triggered();

    void on_actionView_RAT_Test_Record_triggered();

    void on_actionUpload_RAT_Test_triggered();

    void on_actionDownload_COVID_19_Certificate_triggered();

    void on_actionReport_Issues_triggered();

    void on_actionUpdate_Profile_triggered();

    void on_actionChange_Password_triggered();

private:
    Ui::Dashboard *ui;
    UpdateProfile *updateprofile;
    ViewCovidTestResult *viewcovidtestresult;
    UploadSelfTest *uploadselftest;
    ChangePassword *changepassword;

};

#endif // DASHBOARD_H
