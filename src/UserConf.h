#pragma once

#include <QtCore>

#include "Models/CourseAttendance.h"

namespace Lumen {
    class UserConf : public QObject {
        Q_OBJECT

    public:
        ~UserConf();

        QList<const CourseAttendance*> courseAttendances();

        void loadFromMemory(const QByteArray& data);
        void loadFromDisk(const QString& file);
        void saveToDisk(const QString& file);

    public slots:
        void addCourseAttendance(const CourseAttendance* ca);
        void removeCourseAttendance(const CourseAttendance* ca);

    signals:
        void courseAttendanceAdded(const CourseAttendance* ca);
        void courseAttendanceRemoved(const CourseAttendance* ca);

    private:
        QSet<const CourseAttendance*> m_attendances;
    };
}
