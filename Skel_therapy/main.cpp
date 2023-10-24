#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickView>
#include "skelpointloader.h"
#include <QDebug>



static QObject *UserInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    SkelPointLoader *m_skelpointloader = SkelPointLoader::getInstance();
    return m_skelpointloader ;
}


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    SkelPointLoader *skelpointloader = new SkelPointLoader;
    qmlRegisterSingletonType<SkelPointLoader>("skelpointloader", 1, 0, "SkelPointLoader", UserInstance);



    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
    skelpointloader->loadNSaveSkel();
    return app.exec();

//    QQuickView view;
//    view.setSource(QUrl("qrc:/main.qml"));
//    view.show();
    return app.exec();
}


