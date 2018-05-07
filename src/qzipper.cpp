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
QZipper::slot_Compression(){
    //QArchive::Extractor("/media/veracrypt1/UntitledFolder/SkyChat.bak.7z","/media/veracrypt1/UntitledFolder" ).start().waitForFinished();
    //QArchive
}

void
QZipper::slot_Decompression(const QString & path){
    std::cout << "extract file " << path.toStdString() << std::endl;
}
