#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "RepositoryManager.h"

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qt/qml/Lumen/qml/Main.qml"_qs);
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

    Lumen::RepositoryManager& repoManager = Lumen::RepositoryManager::instance();

    repoManager.loadFromDisk("db.json");

    int retCode = app.exec();

    repoManager.saveToDisk("db.json");

    return retCode;
}
