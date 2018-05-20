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
Logger::writeLog(const QString & msg){

    this->_mutex.lock();

    if (!this->_file->open(QIODevice::WriteOnly | QIODevice::Text)) {
        this->_mutex.unlock();
        return;
    }

    this->_file->write(msg.toLocal8Bit());

    this->_file->waitForBytesWritten(100);

    this->_file->close();


    this->_mutex.unlock();

    return;
}

QString
Logger::readLog(){

    this->_mutex.lock();

    if (!this->_file->open(QIODevice::ReadOnly | QIODevice::Text)){
        this->_mutex.unlock();
        return "";
    }
    this->_file->waitForReadyRead(100);
    QString re = this->_file->readAll();
    this->_file->close();
    this->_mutex.unlock();
    return re;
}

bool
Logger::resetLog(){
    this->_mutex.lock();

    this->_file->open(QFile::WriteOnly|QFile::Truncate);
    this->_file->close();

}

bool
Logger::removeFileLog(){
    std::cout << "remove File" << std::endl;
}
