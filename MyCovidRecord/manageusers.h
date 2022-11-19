#ifndef MANAGEUSERS_H
#define MANAGEUSERS_H
#include <QDialog>
#include <QMainWindow>
#include <QItemDelegate>

namespace Ui {
class ManageUsers;
}

class ManageUsers : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageUsers(QWidget *parent = nullptr);
    ~ManageUsers();

public slots:
//    void onInfoPassed10(QString uemail);

private slots:
//    void on_updatUser_accepted();

//    void on_updatUser_rejected();

    void on_updatUser_clicked();

private:
    Ui::ManageUsers *ui;
};

class NotEditableDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit NotEditableDelegate(QObject *parent = 0)
        : QItemDelegate(parent)
    {}

protected:
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
    { return false; }
    QWidget* createEditor(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const
    { return Q_NULLPTR; }

};

#endif // MANAGEUSERS_H
