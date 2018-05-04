#include "qzipper.h"

QZipper::QZipper(QObject *parent) : QObject(parent)
{
    std::cout << "create QZipper object" << std::endl;

    QArchive::Extractor("/home/hydra/Downloads/update_linux.zip","/home/hydra/Desktop/Untitled Folder" ).start().waitForFinished();

    std::cout << "extract done" << std::endl;
}

QZipper::~QZipper()
{
    std::cout << "destroy QZipper object" << std::endl;
}
