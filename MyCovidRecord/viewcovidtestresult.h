#ifndef VIEWCOVIDTESTRESULT_H
#define VIEWCOVIDTESTRESULT_H

#include <QDialog>

namespace Ui {
class ViewCovidTestResult;
}

class ViewCovidTestResult : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCovidTestResult(QWidget *parent = nullptr);
    ~ViewCovidTestResult();

public slots:
    void onInfoPassed3(QString uemail);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ViewCovidTestResult *ui;
};

#endif // VIEWCOVIDTESTRESULT_H
