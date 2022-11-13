#ifndef REPORTERROR_H
#define REPORTERROR_H

#include <QDialog>

namespace Ui {
class ReportError;
}

class ReportError : public QDialog
{
    Q_OBJECT

public:
    explicit ReportError(QWidget *parent = nullptr);
    ~ReportError();

public slots:
    void onInfoPassed7(QString uemail);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ReportError *ui;
};

#endif // REPORTERROR_H
