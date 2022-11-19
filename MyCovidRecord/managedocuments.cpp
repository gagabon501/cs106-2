#include "managedocuments.h"
#include "ui_managedocuments.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QByteArray>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QScreen>

manageDocuments::manageDocuments(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manageDocuments)
{
    ui->setupUi(this);
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel;

    this->setFixedSize(this->size()); //don't allow resizing
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //stretch columns to fill the whole table space
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center()); //center the form in the main window

    query->prepare("SELECT * from user_docs");
    query->exec();

    model->setQuery(std::move(*query)); //to resolve the warning

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true); //hide 'id' column
    ui->tableView->setColumnHidden(5,true); //hide 'file_contents' column

}

manageDocuments::~manageDocuments()
{
    delete ui;
}


void manageDocuments::on_updatUser_clicked()
{
    this->close();

}


//This is executed when the user double-clicks anywhere in the table view
void manageDocuments::on_tableView_activated(const QModelIndex &index)
{
    QString id = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString(); //pick the 'id' column as this will be your unique search key

    QSqlQuery *query = new QSqlQuery();
    if( !query->exec( "SELECT filename, file_contents from user_docs where id='"+id+"'" ))
            qDebug() << "Query error: " << query->lastError();

    query->first(); //If query is successful, I'm sure there is only one record for this since the 'id' is a PRIMARY KEY

//    QString outFileName = query->value(0).toString();
    QString outFileName = QFileDialog::getSaveFileName(this,"Save As");

    QFile file(outFileName);
    if (!file.open(QFile::WriteOnly)) {  // was | QFile::Text))
        qDebug() << "Unable to open file.";
    } else {
        QByteArray outByteArray = query->value(1).toByteArray();
        file.write(outByteArray);
        qDebug() << "Downloaded: " << outFileName;

    }




}

