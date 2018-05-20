#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include "QThread"
#include <QMutex>
#include "logger.h"

class WorkerRead : public QObject
{
    Q_OBJECT
public:
    explicit WorkerRead(QObject *parent = nullptr);

signals:
    void    resultReady(const QString&);

public slots:
    void doWork();
};


class WorkerWrite : public QObject
{
    Q_OBJECT
public:
    explicit WorkerWrite(QObject *parent = nullptr);

signals:
    void    resultReady(const QString&);

public slots:
    void doWork();
};

class ControllerRead : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    ControllerRead() {
        WorkerRead *worker = new WorkerRead;
        worker->moveToThread(&workerThread);
        connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
        connect(this, &ControllerRead::operate, worker, &WorkerRead::doWork);
        connect(worker, &WorkerRead::resultReady, this, &ControllerRead::handleResults);
        workerThread.start();
        emit operate("");
        qDebug() << "Create ControllerRead";
    }
    ~ControllerRead() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    void handleResults(const QString &);
signals:
    void operate(const QString &);
};

class ControllerWrite : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    ControllerWrite() {
        WorkerWrite *worker = new WorkerWrite;
        worker->moveToThread(&workerThread);
        connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
        connect(this, &ControllerWrite::operate, worker, &WorkerWrite::doWork);
        connect(worker, &WorkerWrite::resultReady, this, &ControllerWrite::handleResults);
        workerThread.start();
        emit operate("");
        qDebug() << "Create ControllerWrite";
    }
    ~ControllerWrite() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    void handleResults(const QString &);
signals:
    void operate(const QString &);
};

#endif // WORKER_H
