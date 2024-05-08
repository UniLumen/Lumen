#include "UserConf.h"

#include "RepositoryManager.h"

namespace Lumen {

    QList<const Course*> UserConf::courses() {
        return m_course.values();
    }

    void UserConf::addCourse(const Course* course) {
        if (m_course.contains(course)) {
                return;
        }

        m_course.insert(course);
        emit courseAdded(course);
    }

    void UserConf::removeCourse(const Course* course) {
        if (!m_course.contains(course)) {
            return;
        }

        m_course.remove(course);
        emit courseRemoved(course);
    }

    void UserConf::loadFromMemory(const QByteArray& data) {
        QJsonObject root = QJsonDocument::fromJson(data).object();

        Q_ASSERT(root.contains("courses"));

        QJsonArray arr = root.value("courses").toArray();
        for (const auto& v : arr) {
            QUuid id = QUuid::fromString(v.toString());
            Course* course = RepositoryManager::instance().courseRepo.get(id);
            addCourse(course);
        }
    }

    void UserConf::loadFromDisk(const QString& file) {
        QFile f(file);

        if (!f.open(QIODevice::ReadOnly)) {
            qWarning() << "Error reading from" << file << ":" << f.errorString();
        } else {
            loadFromMemory(f.readAll());
        }
    }

    void UserConf::saveToDisk(const QString& file) {
        QFile f(file);

        if (!f.open(QIODevice::WriteOnly)) {
            qCritical() << "Error writing to" << file << ":" << f.errorString();
        } else {
            QJsonObject json;

            QJsonArray arr;
            for (const auto& c : m_course) {
                arr.push_back(c->id().toString());
            }
            json["courses"] = arr;

            f.write(QJsonDocument(json).toJson());
        }
    }
}

