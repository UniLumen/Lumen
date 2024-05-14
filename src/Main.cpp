#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include "RepositoryManager.h"
#include "schedule.h"
// #include "timeslot.h"

#include "timeslotmodel.h"
// TimeSlotModel test;
void cleanup() {
    QString testt = "hi";
    qDebug()<<testt;
    // qDebug()<<test.dayGrid[0].size();
    //qDebug()<<Schedule::schedules.at(Schedule::schedules.size() - 1)->at(0).course;
    Schedule::FormatSchedule();

    auto currentDay = Schedule::formatedSchedules;
    for(int i = 0; i <currentDay.size();i++)
    {
        for(int j = 0; j <currentDay[i].size();j++)
        {
            for(int k = 0; k < currentDay[i][j].size();k++)
            {
                if(currentDay[i][j][k].course == "") continue;
                qDebug()<<currentDay[i][j][k].day;
                qDebug()<<currentDay[i][j][k].timePeriod;
                qDebug()<<currentDay[i][j][k].sectionNumbers;
                qDebug()<<currentDay[i][j][k].course;
                qDebug()<<currentDay[i][j][k].place;
            }
        }
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


    qDebug()<<Schedule::schedules.size();

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    Lumen::RepositoryManager& repoManager = Lumen::RepositoryManager::instance();

    repoManager.loadFromDisk("db.json");

    int retCode = app.exec();

    repoManager.saveToDisk("db.json");


    return retCode;
}
