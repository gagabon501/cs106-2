#ifndef UPLOADFILE_H
#define UPLOADFILE_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class UploadFile;
}

class UploadFile : public QDialog
{
    Q_OBJECT

public:
    explicit UploadFile(QWidget *parent = nullptr);
    ~UploadFile();

public slots:
    void onInfoPassed10(QString uemail);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();



private:
    Ui::UploadFile *ui;
};

#endif // UPLOADFILE_H
