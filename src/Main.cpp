#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
<<<<<<< HEAD
    const QUrl url(u"qrc:/qt/qml/Lumen/qml/Main.qml"_qs);
=======
    const QUrl            url(u"qrc:/qt/qml/lumen/Main.qml"_qs);
>>>>>>> af28fad (Migrate from QtQuick Design Studio project to QtQuick project)
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl) {
                QCoreApplication::exit(-1);
            }
        },
        Qt::QueuedConnection);
    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
