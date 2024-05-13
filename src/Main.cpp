#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include "RepositoryManager.h"
// #include "timeslot.h"

#include "timeslotmodel.h"
// TimeSlotModel test;
void cleanup() {
    QString testt = "hi";
    qDebug()<<testt;
    // qDebug()<<test.dayGrid[0].size();
    for(int i = 0; i < TimeSlotModel::dataSet[0].size();i++)
    {
        qDebug()<<TimeSlotModel::dataSet[0][i].day;
        qDebug()<<TimeSlotModel::dataSet[0][i].timePeriod;
        qDebug()<<TimeSlotModel::dataSet[0][i].place;
        qDebug()<<TimeSlotModel::dataSet[0][i].course;
    }
}
int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);
    // TimeSlot a(5);
    // if(a.timePeriod == TimeSlot::TimePeriod::Period_6_8)
    //     qDebug() << "ohhhhhhhh yeaaaaaaaaaaaah";
    // qDebug() << static_cast<int>(a.timePeriod);
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qt/qml/Lumen/qml/Main.qml"_qs);
    QQmlContext *context = engine.rootContext();
    qmlRegisterType<TimeSlotModel>("Time", 1, 0, "TimeSlot");
    QObject::connect(&app, &QCoreApplication::aboutToQuit, &cleanup);
    // context->setContextProperty("_testtest", &test);
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
