#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "skelpointloader.h"

static QObject *UserInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    SkelPointLoader *skelpointloader = SkelPointLoader::getInstance();

    return skelpointloader;
}

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    SkelPointLoader *skelpointloader = new SkelPointLoader();
    qmlRegisterSingletonType<SkelPointLoader>("skelpointloader", 1, 0, "SkelPointLoader", UserInstance);
    skelpointloader->loadNSaveSkel();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}

