#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}


void
Worker::doWork()
{
    int count = 0 ;
    while (count < 100){
        Logger::sharedInstance()->writeLog("test write log thread");
        ++count;
        QThread::sleep(1);
    }
    return;
}
