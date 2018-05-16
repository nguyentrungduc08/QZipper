#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QObject>
#include <QFile>
#include <QDateTime>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);

private:


signals:

public slots:

};

#endif // LOGGER_H
