#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include "skelpointloader.h"
#include <QDebug>

static QObject *UserInstance(QQmlEngine *, QJSEngine *);


int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    skelpointloader *m_skelpointloader = new skelpointloader();
    QQmlApplicationEngine engine;

    qmlRegisterSingletonType<skelpointloader>("skelpointloader", 1, 0, "SPK", UserInstance);
    m_skelpointloader->loadNSaveSkel();


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}


static QObject *UserInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    skelpointloader *m_skelpointloader = skelpointloader::getInstance();
    return m_skelpointloader ;
}

