#include "qzipper.h"

QZipper::QZipper(QObject *parent) : QObject(parent)
{
    std::cout << "create QZipper object" << std::endl;

    zipper::Unzipper unzipper("/home/hydra/Downloads/update_linux.zip");
    unzipper.extract();
    unzipper.close();

    std::cout << "extract done" << std::endl;
}

QZipper::~QZipper()
{
    std::cout << "destroy QZipper object" << std::endl;
}
