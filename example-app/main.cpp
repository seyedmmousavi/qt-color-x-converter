#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "colorxlib.h"
#include <QDebug>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

//    HSL *h = ColorXlib::rgb(0, 191, 253)->hsl();
//    qDebug() << h->string();
//    delete h;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //qmlRegisterType<Color>("ir.ColorXlib", 1, 0, "Color");
    ColorXlib c;
    //qmlRegisterSingletonType<ColorXlib>("ir.ColorXlib", 1, 0, "ColorX", &ColorXlib::colorXSingletonProvider);
    //ColorXlib::registerQml();

    //QScopedPointer<ColorXlib> colorX(new ColorXlib);
    //qmlRegisterSingletonInstance("ir.ColorX", 1, 0, "ColorX", colorX.get());
    //qmlRegisterSingletonType<

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
