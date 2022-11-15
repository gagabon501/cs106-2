#ifndef GAGQR_H
#define GAGQR_H

#include <QDialog>
#include "QRWidget.hpp"

namespace Ui {
class gagqr;
}

class gagqr : public QDialog
{
    Q_OBJECT

public:
    explicit gagqr(QWidget *parent = nullptr);
    ~gagqr();

private slots:
    void on_pushButton_clicked();

private:
    Ui::gagqr *ui;
    QRWidget *qrwidget;

};

#endif // GAGQR_H
