#pragma once

#include <QtCore>

#include "Models/Course.h"

namespace Lumen {
    class UserConf : public QObject {
        Q_OBJECT

    public:
        QList<const Course*> courses();

        void loadFromMemory(const QByteArray& data);
        void loadFromDisk(const QString& file);
        void saveToDisk(const QString& file);

    public slots:
        void addCourse(const Course* course);
        void removeCourse(const Course* course);

    signals:
        void courseAdded(const Course* course);
        void courseRemoved(const Course* course);

    private:
        QSet<const Course*> m_course;
    };
}
