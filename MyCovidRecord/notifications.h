#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <QMainWindow>

namespace Ui {
class notifications;
}

class notifications : public QMainWindow
{
    Q_OBJECT

public:
    explicit notifications(QWidget *parent = nullptr);
    ~notifications();

private:
    Ui::notifications *ui;
};

#endif // NOTIFICATIONS_H
