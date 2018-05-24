#include "logger.h"
#include <QDebug>

Logger* Logger::_instance = NULL;

Logger::Logger(QObject *parent) : QObject(parent)
{
    this->_filePathLog = QCoreApplication::applicationDirPath() + "/" +"Qzipper.log";
    this->_file = new QFile(this->_filePathLog);
    this->resetLog();
}

Logger::~Logger(){
    this->removeFileLog();
}

Logger*
Logger::sharedInstance()
{
    if (_instance == NULL) {
        _instance = new Logger();
    }
    return _instance;
}

void
Logger::writeLog(const QString & msg){;

    qDebug() << "before log: " << msg;

    QMutexLocker loc(&this->_mutex);

    if (!this->_file->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {

        return;
    }
    qDebug() << "....";
    this->_file->write(msg.toLocal8Bit(), qstrlen(msg.toLocal8Bit()));

//    this->_file->waitForBytesWritten(100);

    this->_file->close();

    return;
}

QString
Logger::readLog(){

//    this->_mutex.lock();
    QMutexLocker loc(&this->_mutex);

    if (!this->_file->open(QIODevice::ReadOnly | QIODevice::Text)){

        return "";
    }

    QString re = this->_file->readAll();
    this->_file->close();

    return re;
}

bool
Logger::resetLog(){
//    QMutexLocker loc(&this->_mutex);
    this->_file->open(QFile::WriteOnly|QFile::Truncate);
    this->_file->close();
    return true;
}

bool
Logger::removeFileLog(){
    std::cout << "remove File" << std::endl;
}
