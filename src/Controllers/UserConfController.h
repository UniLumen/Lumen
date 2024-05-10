#pragma once


#include <QtCore>

#include "UserConf.h"
#include "Views/CourseListView.h"

namespace Lumen {
    class UserConfController : public QObject {
        Q_OBJECT

    public:
        UserConfController(UserConf* userConf, CourseListView* courseListView);
        ~UserConfController();

    public slots:
        void addCourseAttendance(const QUuid& id, bool lecture, bool lab, bool tutorial);

    private:
        UserConf* m_userConf;
        CourseListView* m_courseListView;
        QVector<QMetaObject::Connection> m_connections;
    };
}
