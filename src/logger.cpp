#include "logger.h"

Logger::Logger(QObject *parent) : QObject(parent)
{
    // enable sinks
    simpleqtlogger::ENABLE_LOG_SINK_FILE = true;
    simpleqtlogger::ENABLE_LOG_SINK_CONSOLE = true;
    simpleqtlogger::ENABLE_LOG_SINK_QDEBUG = false;
    simpleqtlogger::ENABLE_LOG_SINK_SIGNAL = false;
    // set log-features
    simpleqtlogger::ENABLE_FUNCTION_STACK_TRACE = true;
    simpleqtlogger::ENABLE_CONSOLE_COLOR = true;
    simpleqtlogger::ENABLE_CONSOLE_TRIMMED = true;
    // set log-levels (global; all enabled)
    simpleqtlogger::ENABLE_LOG_LEVELS.logLevel_DEBUG = true;
    simpleqtlogger::ENABLE_LOG_LEVELS.logLevel_FUNCTION = true;
    // set log-levels (specific)
    simpleqtlogger::EnableLogLevels enableLogLevels_file = simpleqtlogger::ENABLE_LOG_LEVELS;
    simpleqtlogger::EnableLogLevels enableLogLevels_console = simpleqtlogger::ENABLE_LOG_LEVELS;
    simpleqtlogger::EnableLogLevels enableLogLevels_qDebug = simpleqtlogger::ENABLE_LOG_LEVELS;
    simpleqtlogger::EnableLogLevels enableLogLevels_signal = simpleqtlogger::ENABLE_LOG_LEVELS;
    enableLogLevels_console.logLevel_FUNCTION = false;
    simpleqtlogger::EnableLogLevels enableLogLevels_fileWarn = simpleqtlogger::ENABLE_LOG_LEVELS;
    enableLogLevels_fileWarn.logLevel_NOTE = false;
    enableLogLevels_fileWarn.logLevel_INFO = false;
    enableLogLevels_fileWarn.logLevel_DEBUG = false;
    enableLogLevels_fileWarn.logLevel_FUNCTION = false;

    std::cout << "create loger " << std::endl;

    simpleqtlogger::SimpleQtLogger::createInstance(qApp)->setLogFormat_file("<TS> [<LL>] <TEXT> (<FUNC>@<FILE>:<LINE>)", "<TS> [<LL>] <TEXT>");
    simpleqtlogger::SimpleQtLogger::getInstance()->setLogFileName(QDir::home().filePath("Documents/Qt/testSimpleQtLoggerGui.log"), 10*1000, 10);

    std::cout << QDir::home().filePath("azip.log").toStdString() << std::endl;

    simpleqtlogger::SimpleQtLogger::getInstance()->setLogLevels_file(enableLogLevels_file);
    simpleqtlogger::SimpleQtLogger::getInstance()->setLogLevels_console(enableLogLevels_console);
    simpleqtlogger::SimpleQtLogger::getInstance()->setLogLevels_qDebug(enableLogLevels_qDebug);
    simpleqtlogger::SimpleQtLogger::getInstance()->setLogLevels_signal(enableLogLevels_signal);
}

void
Logger::writeLog(const QString & msg){
    L_NOTE(msgs);
}
