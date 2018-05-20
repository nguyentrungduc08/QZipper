#ifndef LOGGER_H
#define LOGGER_H

#include <QCoreApplication>
#include <QObject>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <iostream>


class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);
    ~Logger();

    static Logger*      sharedInstance();

    // String write log
    void                writeLog(const QString & msg);

    // read all data from file log
    QString             readLog();

    // reset all data log file
    bool                resetLog();

    // remove file log
    bool                removeFileLog();

private:
    QString             _logPlatform;
    QString             _logAction;
    QString             _logSender;
    QString             _logReceiver;
    QString             _logMSGID;
    QString             _logMSGSS;

    QString             _filePathLog;
    static Logger       *_instance;

signals:

};

#endif // LOGGER_H
