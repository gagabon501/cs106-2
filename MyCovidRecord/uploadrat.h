#ifndef UPLOADRAT_H
#define UPLOADRAT_H

#include <QDialog>

namespace Ui {
class UploadRAT;
}

class UploadRAT : public QDialog
{
    Q_OBJECT

public:
    explicit UploadRAT(QWidget *parent = nullptr);
    ~UploadRAT();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::UploadRAT *ui;
};

#endif // UPLOADRAT_H
