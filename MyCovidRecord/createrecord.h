#ifndef CREATERECORD_H
#define CREATERECORD_H

#include <QMainWindow>

namespace Ui {
class CreateRecord;
}

class CreateRecord : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateRecord(QWidget *parent = nullptr);
    ~CreateRecord();

private slots:
    void on_pushButton_3_customContextMenuRequested(const QPoint &pos);

private:
    Ui::CreateRecord *ui;
};

#endif // CREATERECORD_H
