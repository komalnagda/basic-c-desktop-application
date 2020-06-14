#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QtDebug>
#include <QQmlContext>
#include <mybuttonhandler.h>


int main(int argc, char *argv[])
{
    MyButtonHandler myButtonHandler;
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("myButtonHandler", &myButtonHandler);
    engine.load(QUrl("qrc:/main.qml"));



    return app.exec();
}
