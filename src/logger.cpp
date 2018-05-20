#include "logger.h"
#include <QDebug>

Logger* Logger::_instance = NULL;

Logger::Logger(QObject *parent) : QObject(parent)
{

    this->_filePathLog = QCoreApplication::applicationDirPath() + "/" +"Qzipper.log";
    // enable sinks
    simpleqtlogger::ENABLE_LOG_SINK_FILE = true;
//    simpleqtlogger::ENABLE_LOG_SINK_CONSOLE = true;
    simpleqtlogger::ENABLE_LOG_SINK_QDEBUG = false;
    simpleqtlogger::ENABLE_LOG_SINK_SIGNAL = false;
    // set log-features
    simpleqtlogger::ENABLE_FUNCTION_STACK_TRACE = true;
    simpleqtlogger::ENABLE_CONSOLE_COLOR = false;
    simpleqtlogger::ENABLE_CONSOLE_TRIMMED = true;
    // set log-levels (global; all enabled)
    simpleqtlogger::ENABLE_LOG_LEVELS.logLevel_DEBUG = true;
    simpleqtlogger::ENABLE_LOG_LEVELS.logLevel_FUNCTION = true;
    // set log-levels (specific)
    simpleqtlogger::EnableLogLevels enableLogLevels_file = simpleqtlogger::ENABLE_LOG_LEVELS;
//    simpleqtlogger::EnableLogLevels enableLogLevels_console = simpleqtlogger::ENABLE_LOG_LEVELS;
    simpleqtlogger::EnableLogLevels enableLogLevels_qDebug = simpleqtlogger::ENABLE_LOG_LEVELS;
    simpleqtlogger::EnableLogLevels enableLogLevels_signal = simpleqtlogger::ENABLE_LOG_LEVELS;
//    enableLogLevels_console.logLevel_FUNCTION = false;
    simpleqtlogger::EnableLogLevels enableLogLevels_fileWarn = simpleqtlogger::ENABLE_LOG_LEVELS;
    enableLogLevels_fileWarn.logLevel_NOTE = false;
    enableLogLevels_fileWarn.logLevel_INFO = false;
    enableLogLevels_fileWarn.logLevel_DEBUG = false;
    enableLogLevels_fileWarn.logLevel_FUNCTION = false;

    simpleqtlogger::SimpleQtLogger::createInstance(this)->setLogFormat_file("<TS> <TEXT> ","");
    simpleqtlogger::SimpleQtLogger::getInstance()->setLogFileName(this->_filePathLog, 10*1000, 10);
    simpleqtlogger::SimpleQtLogger::getInstance()->setLogLevels_file(enableLogLevels_file);
//    simpleqtlogger::SimpleQtLogger::getInstance()->setLogLevels_console(enableLogLevels_console);
    simpleqtlogger::SimpleQtLogger::getInstance()->setLogLevels_qDebug(enableLogLevels_qDebug);
    simpleqtlogger::SimpleQtLogger::getInstance()->setLogLevels_signal(enableLogLevels_signal);

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
    L_NOTE(msg);
}

QString
Logger::readLog(){
    QFile f((QCoreApplication::applicationDirPath() + "/" + "Qzipper.log"));
    if (!f.open(QFile::ReadOnly | QFile::Text)) return "";
    QTextStream in(&f);
//    qDebug() << f.size() << in.readAll();
    return in.readAll();
}

bool
Logger::resetLog(){
    QFile file((QCoreApplication::applicationDirPath() + "/" + "Qzipper.log"));
    return file.open(QFile::WriteOnly|QFile::Truncate);
}

bool
Logger::removeFileLog(){
    std::cout << "remove File" << std::endl;
}
