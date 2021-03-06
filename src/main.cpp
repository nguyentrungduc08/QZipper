#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QMessageLogger>
#include <QMessageLogContext>
#include <QList>
#include "qzipper.h"
#include "logger.h"
#include "worker.h"
#include  <QApplication>
#include <iostream>

class object{
public:
    int a;
    object(int i){
        a = i;
        std::cout << "create object " << a << std::endl;
    }

    ~object(){
        std::cout << "release object " << a <<  std::endl;
    }

    object(const object& aaa){
        this->a = aaa.a;
        std::cout << "this is copy constructor " << a << std::endl;
    }
};

QList<object> funcA(){
    QList<object> list;
    for(int i = 1; i < 5; ++i){
        std::cout <<" ________" << std::endl;
        object obj(i);
        obj.a = i;
        list.append(obj);
        std::cout <<" ________" << std::endl;
    }
    return list;
}

QList<object> funcB(){
    QList<object> list;
    for(int i = 10; i < 15; ++i){
        std::cout <<" ________" << std::endl;
        object obj(i);
        obj.a = i;
        list.append(obj);
        std::cout <<" ________" << std::endl;
    }
    return list;
}

void fun(){
    {
        QList<object> listA= funcA();
        QList<object> listB= funcB();
        for(int i = 0; i < listA.count(); ++i){
            std::cout << " log " << listA[i].a << std::endl;
        }

        for(int i = 0; i < listB.count(); ++i){
            std::cout << " log " << listB[i].a << std::endl;
        }
    }
}


int main(int argc, char *argv[])
{
    std::cout << "log: " << __LINE__ << __FUNCTION__ << std::endl;


    ControllerR *con = new ControllerR;

    const char * url = "QZipper";
    qmlRegisterType<QZipper>(url,1,0,"QZipper");

//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    //ControllerWrite *contWrite = new ControllerWrite;


    //ControllerRead *contRead = new ControllerRead;

    QIcon icon(":/resources/zipper.png");
    app.setWindowIcon(icon);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
