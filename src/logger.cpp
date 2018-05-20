#include "logger.h"
#include <QDebug>

Logger* Logger::_instance = NULL;

Logger::Logger(QObject *parent) : QObject(parent)
{
    this->_filePathLog = QCoreApplication::applicationDirPath() + "/" +"Qzipper.log";

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
    QFile file(this->_filePathLog);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    file.write(msg.toLocal8Bit());
    file.waitForBytesWritten(10);
    file.close();
}

QString
Logger::readLog(){
    QFile f(this->_filePathLog);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) return "";

//    qDebug() << f.size() << in.readAll();
    QString re = f.readAll();
    f.waitForReadyRead(10);
    f.close();
    f.remove();
    return re;
}

bool
Logger::resetLog(){

    QFile file(this->_filePathLog);
    bool f = file.open(QFile::WriteOnly|QFile::Truncate);
    file.close();

    return f;
}

bool
Logger::removeFileLog(){
    std::cout << "remove File" << std::endl;
}
