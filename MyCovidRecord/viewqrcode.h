#ifndef VIEWQRCODE_H
#define VIEWQRCODE_H

#include "QRWidget.hpp"

#include <QDialog>

namespace Ui {
class ViewQrCode;
}

class ViewQrCode : public QDialog
{
    Q_OBJECT

public:
    explicit ViewQrCode(QWidget *parent = nullptr);
    ~ViewQrCode();

public slots:
    void onInfoPassed9(QString uemail);

private:
    Ui::ViewQrCode *ui;
    QRWidget *qrwidget;
};

#endif // VIEWQRCODE_H
