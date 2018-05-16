#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QObject>
#include <QFile>
#include <QDateTime>
#include <iostream>
#include <QApplication>

#include <simpleQtLogger.h>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);

private:


signals:

public slots:
    void    writeLog(const QString & msg);

};

#endif // LOGGER_H
