#include "systemlog.h"

//SystemLog(QObject *parent = nullptr, QString email="", QString source="")
SystemLog::SystemLog(QObject *parent,QString email, QString source, QString message)
    : QObject{parent}
{
      QSqlQuery query;

      dateLog = QDateTime::currentDateTime().toString();
      logSource = source;
      logMessage = message;

      query.prepare("INSERT INTO system_logs (date_log, email, log_message, log_source) VALUES (?,?,?,?)");

      query.addBindValue(dateLog);
      query.addBindValue(email);
      query.addBindValue(logSource);
      query.addBindValue(logMessage);

      if(query.exec()) {
          qDebug() << "Record added.";
      } else {
          qDebug() << "Error adding: " << query.lastError();
      };


}
