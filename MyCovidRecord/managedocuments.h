#ifndef MANAGEDOCUMENTS_H
#define MANAGEDOCUMENTS_H
#include <QDialog>
#include <QMainWindow>

namespace Ui {
class manageDocuments;
}

class manageDocuments : public QMainWindow
{
    Q_OBJECT

public:
    explicit manageDocuments(QWidget *parent = nullptr);
    ~manageDocuments();

private slots:


    void on_updatUser_clicked();

private:
    Ui::manageDocuments *ui;

};

#endif // MANAGEDOCUMENTS_H
