#ifndef UPLOADSELFTEST_H
#define UPLOADSELFTEST_H

#include <QDialog>

namespace Ui {
class UploadSelfTest;
}

class UploadSelfTest : public QDialog
{
    Q_OBJECT

public:
    explicit UploadSelfTest(QWidget *parent = nullptr);
    ~UploadSelfTest();

public slots:
    void onInfoPassed2(QString uemail);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::UploadSelfTest *ui;
};

#endif // UPLOADSELFTEST_H
