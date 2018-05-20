#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "logger.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:
    void    resultReady(const QString&);

public slots:
    void doWork();
};

#endif // WORKER_H
