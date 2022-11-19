#ifndef SYSTEMLOG_H
#define SYSTEMLOG_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTimeEdit>

class SystemLog : public QObject
{
    Q_OBJECT
public:
    explicit SystemLog(QObject *parent = nullptr, QString email="", QString source="", QString message="");

    QString dateLog;
    QString email;
    QString logMessage;
    QString logSource;

signals:

};

#endif // SYSTEMLOG_H
