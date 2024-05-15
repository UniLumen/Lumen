#include "UserConf.h"

#include "JsonReader.h"
#include "Models/CourseAttendance.h"

namespace Lumen {

    UserConf::~UserConf() {
        for (auto& ca : m_attendances) {
            emit courseAttendanceRemoved(ca);
        }
        qDeleteAll(m_attendances);
    }

    QList<const CourseAttendance*> UserConf::courseAttendances() {
        return m_attendances.values();
    }

    void UserConf::addCourseAttendance(const CourseAttendance* ca) {
        // This is bad
        for (auto& c : m_attendances) {
            if (*c == *ca) {
                return;
            }
        }

        if (m_attendances.contains(ca)) {
            return;
        }

        m_attendances.insert(ca);
        emit courseAttendanceAdded(ca);
    }

    void UserConf::removeCourseAttendance(const CourseAttendance* ca) {
        if (!m_attendances.contains(ca)) {
            return;
        }

        m_attendances.remove(ca);
        emit courseAttendanceRemoved(ca);
        delete ca;
    }

    void UserConf::loadFromMemory(const QByteArray& data) {
        QJsonObject root = QJsonDocument::fromJson(data).object();

        Q_ASSERT(root.contains("courses"));

        JsonReader reader;
        QJsonArray arr = root.value("courses").toArray();
        for (const auto& v : arr) {
            CourseAttendance* ca = new CourseAttendance();

            ca->fromJson(reader, v);
            if (ca->course()) {
                addCourseAttendance(ca);
            } else {
                delete ca;
            }
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
            for (const auto& a : m_attendances) {
                arr.push_back(a->toJson());
            }
            json["courses"] = arr;

            f.write(QJsonDocument(json).toJson());
        }
    }
}

