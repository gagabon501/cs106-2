#ifndef UPDATEPROFILE_H
#define UPDATEPROFILE_H

#include <QDialog>

namespace Ui {
class UpdateProfile;
}

class UpdateProfile : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateProfile(QWidget *parent = nullptr);
    ~UpdateProfile();


public slots:
    void onInfoPassed1(QString uemail);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::UpdateProfile *ui;
};

#endif // UPDATEPROFILE_H
