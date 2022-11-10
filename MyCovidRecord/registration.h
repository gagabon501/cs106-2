#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_pushButton_Save_clicked();

    void on_lineEdit_ReTypePassword_editingFinished();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
