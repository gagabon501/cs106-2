#ifndef VIEWUSERS_H
#define VIEWUSERS_H

#include <QMainWindow>

namespace Ui {
class viewusers;
}

class viewusers : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewusers(QWidget *parent = nullptr);
    ~viewusers();

private:
    Ui::viewusers *ui;
};

#endif // VIEWUSERS_H
