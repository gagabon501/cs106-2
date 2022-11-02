#ifndef MAINDOCUMENTS_H
#define MAINDOCUMENTS_H

#include <QMainWindow>

namespace Ui {
class mainDocuments;
}

class mainDocuments : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainDocuments(QWidget *parent = nullptr);
    ~mainDocuments();

private:
    Ui::mainDocuments *ui;
};

#endif // MAINDOCUMENTS_H
