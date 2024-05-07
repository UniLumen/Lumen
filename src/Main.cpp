#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QDebug>
#include <QString>
#include "CourseModel.h"
#include "InstructorModel.h"
#include "LocationModel.h"


int main(int argc, char* argv[]) {

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qt/qml/Lumen/qml/Main.qml"_qs);

    QQmlContext *context = engine.rootContext();

    CourseModel courseModel;
    InstructorModel instructorModel;
    LocationModel locationModel;

    context->setContextProperty("_courseModel", &courseModel);
    context->setContextProperty("_instructorModel", &instructorModel);
    context->setContextProperty("_locationModel", &locationModel);

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
