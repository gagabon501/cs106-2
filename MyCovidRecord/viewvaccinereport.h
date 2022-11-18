#ifndef VIEWVACCINEREPORT_H
#define VIEWVACCINEREPORT_H

#include <QDialog>
#include "QRWidget.hpp"

namespace Ui {
class ViewVaccineReport;
}

class ViewVaccineReport : public QDialog
{
    Q_OBJECT

public:
    explicit ViewVaccineReport(QWidget *parent = nullptr);
    ~ViewVaccineReport();


public slots:
    void onInfoPassed6(QString uemail);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ViewVaccineReport *ui;
    QRWidget *qrwidget;
};

#endif // VIEWVACCINEREPORT_H
