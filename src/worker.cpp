#include "worker.h"
#include "QDebug"

WorkerRead::WorkerRead(QObject *parent) : QObject(parent)
{
    qDebug() << "Create worker read";
}

WorkerWrite::WorkerWrite(QObject *parent) : QObject(parent)
{
    qDebug() << "Create worker write";
}

void
WorkerWrite::doWork()
{
    int count = 0 ;
    while (count < 100){
        Logger::sharedInstance()->writeLog(QString("test write log thread" + count));
        ++count;
        qDebug() << "write thread " << count;
        QThread::sleep(1);
    }
    return;
}

void
WorkerRead::doWork()
{
    int count = 0 ;
    while (count < 100){
        qDebug() << "log: \n" << Logger::sharedInstance()->readLog();
//        Logger::sharedInstance()->resetLog();
        ++count;
        qDebug() << "read thread " << count;
        QThread::sleep(5);
    }
    return;
}

void
ControllerRead::handleResults(const QString & result)
{
    qDebug() << result;
}


void
ControllerWrite::handleResults(const QString & result)
{
    qDebug() << result;
}
