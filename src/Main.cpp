#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "scheduleoptimizer.h"
#include "schedule.h"
#include <QQmlContext>
#include <QFont>
#include <QFontDatabase>

#include "Controllers/CourseController.h"
#include "Controllers/InstructorController.h"
#include "Controllers/LocationController.h"
#include "Controllers/UserConfController.h"
#include "RepositoryManager.h"
#include "UserConf.h"
#include "Views/CourseListView.h"
#include "Views/InstructorListView.h"
#include "Views/LocationListView.h"
#include <Views/OptimizedScheduleView.h>

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
    memset(ScheduleOptimizer::dp,-1,sizeof ScheduleOptimizer::dp);
    qDebug()<<ScheduleOptimizer::getMinimumDays(0,0,0,0,Schedule::formatedSchedules);
}
int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    Lumen::RepositoryManager& repoManager = Lumen::RepositoryManager::instance();
    repoManager.loadFromDisk("db.json");

    Lumen::UserConf userConf;
    userConf.loadFromDisk("user.json");

    QList<Course*> allCourses = repoManager.courseRepo.getAll();
    QVector<const ICourse*> courses;
    std::transform(allCourses.constBegin(), allCourses.constEnd(), std::back_inserter(courses), [](Course* c) {
        return static_cast<const ICourse*>(c);
    });

    CourseListView coursesView(courses);
    CourseController courseController(&repoManager.courseRepo, &userConf, &coursesView);

    CourseListView userView;
    userView.setMinCreditHours(12);
    userView.setMaxCreditHours(21);

    UserConfController userController(&userConf, &userView);

    LocationListView locationsView;
    LocationController locationController(&repoManager.locationRepo, &locationsView);

    InstructorListView instructorListView;
    InstructorController instructorController(&repoManager.instructorRepo, &instructorListView);
    OptimizedScheduleView optimizedScheduleView;

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    const QUrl url(u"qrc:/qt/qml/Lumen/qml/Main.qml"_qs);
    qmlRegisterType<TimeSlotModel>("Time", 1, 0, "TimeSlot");
    QObject::connect(&app, &QCoreApplication::aboutToQuit, &cleanup);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl) {
                QCoreApplication::exit(-1);
            }
        },
        Qt::QueuedConnection);

    qDebug()<<Schedule::schedules.size();

    context->setContextProperty("__courseModel", &coursesView);
    context->setContextProperty("__userModel", &userView);
    context->setContextProperty("__optimizedSchedulesModel", &optimizedScheduleView);

    context->setContextProperty("__instructorModel", &instructorListView);
    context->setContextProperty("__locationModel", &locationsView);

    engine.load(url);
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    int retCode = app.exec();

    repoManager.saveToDisk("db.json");
    userConf.saveToDisk("user.json");


    return retCode;
}
