#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "RepositoryManager.h"
#include "UserConf.h"
#include "Views/CourseListView.h"

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    const QUrl url(u"qrc:/qt/qml/Lumen/qml/Main.qml"_qs);
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

    CourseListView coursesView(repoManager.courseRepo.getAll());
    CourseListView userView(userConf.courses());

    QObject::connect(&userConf, &UserConf::courseAdded, &userView, &CourseListView::addCourse);
    QObject::connect(&userConf, &UserConf::courseRemoved, &userView, qOverload<const Course*>(&CourseListView::removeCourse));
    QObject::connect(&userView, &CourseListView::removeCourseRequest, &userConf, [&](int index) {
        // CAUTION: userView.removeCourse is invoked twice

        const Course* removedCourse = userView.removeCourse(index);
        userConf.removeCourse(removedCourse);
    });
    QObject::connect(&userView, &CourseListView::addCourseRequest, &userConf, [&](const QUuid& id) {
        Course* course = RepositoryManager::instance().courseRepo.get(id);
        userConf.addCourse(course);
    });

    userView.setMinCreditHours(12);
    userView.setMaxCreditHours(21);

    context->setContextProperty("__courseModel", &coursesView);
    context->setContextProperty("__userModel", &userView);

    engine.load(url);
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    int retCode = app.exec();

    repoManager.saveToDisk("db.json");
    userConf.saveToDisk("user.json");

    return retCode;
}
