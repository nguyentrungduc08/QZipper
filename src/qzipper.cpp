#include "qzipper.h"

QZipper::QZipper(QObject *parent) : QObject(parent)
{
    std::cout << "create QZipper object" << std::endl;

//    QArchive::Extractor("/media/veracrypt1/UntitledFolder/SkyChat.bak.7z","/media/veracrypt1/UntitledFolder" ).start().waitForFinished();
//    QArchive::Compressor("lib.zip", "lib").start().waitForFinished();
//    QArchive::Compressor("lib.zip", "plugins").start().waitForFinished();
//    QArchive::Compressor("lib.zip", "qml").start().waitForFinished();
//    QArchive::Compressor("lib.zip", "SkyChat").start().waitForFinished();

//    QStringList listString;
//    listString << "lib" << "plugins" << "qml" << "SkyChat";

//    QArchive::Compressor compessor("SkyChat.bak.7z" , listString);
//    compessor.setArchiveFormat(QArchive::SEVEN_ZIP);

//    compessor.start().waitForFinished();

    std::cout << "extract done" << std::endl;
}

QZipper::~QZipper()
{
    std::cout << "destroy QZipper object" << std::endl;
}


void
QZipper::slot_Compression(const QString& pathCompress, const QString& pathFolderToArchvie){
    std::cout << "path compress file or folder: " << pathCompress.toStdString() << std::endl;
    std::cout << "path to save archive: " << pathFolderToArchvie.toStdString() << std::endl;
    QArchive::Compressor compressor;
    compressor.setArchive( "/" + pathFolderToArchvie);
    compressor.addFiles("/" + pathCompress);
    compressor.start().waitForFinished();
    std::cout << "compress finished" << std::endl;
}

void
QZipper::slot_Decompression(const QString& pathFileExtract, const QString& pathFolderToExtract){
    std::cout << "extract file: " << pathFileExtract.toStdString() << std::endl;
    std::cout << "extract to: " << pathFolderToExtract.toStdString() << std::endl;
    QArchive::Extractor extractor;
    extractor.setArchive("/"+pathFileExtract, "/"+pathFolderToExtract);
    extractor.start().waitForFinished();
    std::cout << "extract finished" << std::endl;
}
