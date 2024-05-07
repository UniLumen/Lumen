#include "RepositoryManager.h"

#include "JsonReader.h"

namespace Lumen {
    QSharedPointer<RepositoryManager> RepositoryManager::s_instance(nullptr);

    RepositoryManager& RepositoryManager::instance() {
        if (!s_instance) {
            s_instance.reset(new RepositoryManager);
        }

        return *s_instance;
    }

    void RepositoryManager::loadFromMemory(const QByteArray& data) {
        QJsonObject root = QJsonDocument::fromJson(data).object();

        Q_ASSERT(root.contains("locations"));
        Q_ASSERT(root.contains("doctors"));
        Q_ASSERT(root.contains("tas"));
        Q_ASSERT(root.contains("courses"));

        JsonReader reader;

        locationRepo.fromJson(reader, root["locations"]);
        doctorRepo.fromJson(reader, root["doctors"]);
        taRepo.fromJson(reader, root["tas"]);
        courseRepo.fromJson(reader, root["courses"]);
    }

    void RepositoryManager::loadFromDisk(const QString& file) {
        QFile f(file);

        if (!f.open(QIODevice::ReadOnly)) {
            qWarning() << "Error reading from" << file << ":" << f.errorString();
        } else {
            loadFromMemory(f.readAll());
        }
    }

    void RepositoryManager::saveToDisk(const QString& file) {
        QFile f(file);

        if (!f.open(QIODevice::WriteOnly)) {
            qCritical() << "Error writing to" << file << ":" << f.errorString();
        } else {
            QJsonObject json;

            json["locations"] = locationRepo.toJson();
            json["doctors"] = doctorRepo.toJson();
            json["tas"] = taRepo.toJson();
            json["courses"] = courseRepo.toJson();

            f.write(QJsonDocument(json).toJson());
        }
    }
}

