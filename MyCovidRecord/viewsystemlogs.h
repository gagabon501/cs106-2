#ifndef VIEWSYSTEMLOGS_H
#define VIEWSYSTEMLOGS_H

#include <QDialog>

namespace Ui {
class ViewSystemLogs;
}

class ViewSystemLogs : public QDialog
{
    Q_OBJECT

public:
    explicit ViewSystemLogs(QWidget *parent = nullptr);
    ~ViewSystemLogs();

private:
    Ui::ViewSystemLogs *ui;
};

#endif // VIEWSYSTEMLOGS_H
