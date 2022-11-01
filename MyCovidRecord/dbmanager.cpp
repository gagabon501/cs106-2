#include <dbmanager.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE user(email TEXT PRIMARY KEY, password TEXT, lastname TEXT, firstname TEXT, phone TEXT, gender TEXT, nhi TEXT, level NUMBER, vaccine_status TEXT, dob TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create table USER : one might already exist.";
        success = false;
    }

    query.prepare("CREATE TABLE vaccine(email TEXT, date_entered TEXT, date_administered TEXT, administered_by TEXT, date_expiry TEXT, vaccine_name TEXT, qrcode_string TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create table VACCINE : one might already exist.";
        success = false;
    }

    query.prepare("CREATE TABLE covid_test(email TEXT, date_entered TEXT, date_administered TEXT, administered_by TEXT, test_type TEXT, test_result TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create COVID_TEST table : one might already exist.";
        success = false;
    }
    query.prepare("CREATE TABLE error_logs(email TEXT, date_entered TEXT, log_description TEXT, log_priority NUMBER, log_status TEXT, actioned_by TEXT, remarks TEXT);");


    if (!query.exec())
    {
        qDebug() << "Couldn't create table ERROR_LOGS : one might already exist.";
        success = false;
    }

    return success;
}

bool DbManager::userRegister(const QString& email,const QString& password, const QString& lastname, const QString& firstname,const QString& phone, const QString& gender, const QString& nhi, int level, const QString& vaccine_status,const QString& dob)
{
    bool success = false;

    if (!email.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO user (email,password,lastname,firstname,phone,gender,nhi,level,vaccine_status) VALUES (:email,:password,:lastname,:firstname,:phone,:gender,:nhi,:level,:vaccine_status)");

        queryAdd.bindValue(":email", email);
        queryAdd.bindValue(":password", password);
        queryAdd.bindValue(":lastname", lastname);
        queryAdd.bindValue(":firstname", firstname);
        queryAdd.bindValue(":phone", phone);
        queryAdd.bindValue(":gender", gender);
        queryAdd.bindValue(":nhi", nhi);
        queryAdd.bindValue(":level", level);
        queryAdd.bindValue(":vaccine_status", vaccine_status);


        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add person failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add person failed: email cannot be empty";
    }

    return success;
}

bool DbManager::removePerson(const QString& name)
{
    bool success = false;

    if (personExists(name))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM people WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove person failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove person failed: person doesnt exist";
    }

    return success;
}

void DbManager::printAllPersons() const
{
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM people");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << "===" << name;
    }
}

bool DbManager::personExists(const QString& name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM people WHERE name = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool DbManager::removeAllPersons()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM people");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all persons failed: " << removeQuery.lastError();
    }

    return success;
}

bool DbManager::dbClose() {
    m_db.close();
}
