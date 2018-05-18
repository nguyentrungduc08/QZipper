#include "qzipper.h"

QZipper::QZipper(QObject *parent) : QObject(parent)
{
    std::cout << "create QZipper object" << std::endl;

    std::cout << "extract done" << std::endl;

    Logger::sharedInstance()->writeLog("create QZipper objeccasgfdasfsdgfasdfasdft");

}

QZipper::~QZipper()
{
    std::cout << "destroy QZipper object" << std::endl;
    qDebug() << "log" <<  Logger::sharedInstance()->readLog();
    //qDebug() << "log" <<  Logger::sharedInstance()->resetLog();
}

void
QZipper::slot_Compression(const QString& pathCompress, const QString& pathFolderToArchvie){
    std::cout << "path compress file or folder: " << pathCompress.toStdString() << std::endl;
    std::cout << "path to save archive: " << pathFolderToArchvie.toStdString() << std::endl;
//    QArchive::Compressor compressor;
//    compressor.setArchive( "/" + pathFolderToArchvie);
//    compressor.addFiles("/" + pathCompress);
//    compressor.start().waitForFinished();
    Logger::sharedInstance()->writeLog("path compress file or folder: ");
    std::cout << "compress finished" << std::endl;


}

void
QZipper::slot_Decompression(const QString& pathFileExtract, const QString& pathFolderToExtract){
    std::cout << "extract file: " << pathFileExtract.toStdString() << std::endl;
    std::cout << "extract to: " << pathFolderToExtract.toStdString() << std::endl;
//    QArchive::Extractor extractor;
//    extractor.setArchive("/"+pathFileExtract, "/"+pathFolderToExtract);
//    extractor.start().waitForFinished();
    Logger::sharedInstance()->writeLog("extract finished");
    std::cout << "extract finished" << std::endl;
}
