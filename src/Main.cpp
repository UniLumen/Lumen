#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QString>

#include "Controllers/UserConfController.h"
#include "RepositoryManager.h"
#include "UserConf.h"
#include "Views/CourseListView.h"
#include "CourseModel.h"
#include "InstructorModel.h"
#include "LocationModel.h"


int main(int argc, char* argv[]) {

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    const QUrl url(u"qrc:/qt/qml/Lumen/qml/Main.qml"_qs);
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
    CourseListView userView;
    UserConfController userController(&userConf, &userView);

    userView.setMinCreditHours(12);
    userView.setMaxCreditHours(21);

    context->setContextProperty("__courseModel", &coursesView);
    context->setContextProperty("__userModel", &userView);

    engine.load(url);
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    QObject* courseEditorItem = engine.rootObjects()[0]->children()[1]; //I have no idea why this works
    QObject::connect(courseEditorItem, SIGNAL(removeCourse(int)), &courseModel, SLOT(onRemoveCourse(int)));
    QObject::connect(courseEditorItem, SIGNAL(addCourse(QString,QString,QString,QString)), &courseModel, SLOT(onAddCourse(QString,QString,QString,QString)));


    int retCode = app.exec();

    repoManager.saveToDisk("db.json");
    userConf.saveToDisk("user.json");

    return retCode;
}
