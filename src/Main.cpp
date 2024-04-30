#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QDebug>
#include "CourseModel.h"

int main(int argc, char* argv[]) {

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qt/qml/Lumen/qml/Main.qml"_qs);

    QQmlContext *context = engine.rootContext();

    CourseModel courseModel;
    context->setContextProperty("_courseModel", &courseModel);


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


    QObject* courseEditorItem = engine.rootObjects()[0]->children()[1]; //I have no idea why this works
    QObject::connect(courseEditorItem, SIGNAL(removeCourse(int)), &courseModel, SLOT(onRemoveCourse(int)));


    return app.exec();
}
