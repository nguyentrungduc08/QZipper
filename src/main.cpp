#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QMessageLogger>
#include <QMessageLogContext>
#include "qzipper.h"


int main(int argc, char *argv[])
{
    const char * url = "QZipper";
    qmlRegisterType<QZipper>(url,1,0,"QZipper");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QIcon icon(":/resources/zipper.png");
    app.setWindowIcon(icon);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
