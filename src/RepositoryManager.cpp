#include "RepositoryManager.h"

#include "JsonReader.h"
#include "JsonWriter.h"

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

        JsonReader reader(root);

        reader.fromJsonArray<Location>(root.value("locations").toArray(), [&](Location* loc){
            locationRepo.insert(loc);
        });

        reader.fromJsonArray<Doctor>(root.value("doctors").toArray(), [&](Doctor* doc) {
            doctorRepo.insert(doc);
        });

        reader.fromJsonArray<TA>(root.value("tas").toArray(), [&](TA* ta){
            taRepo.insert(ta);
        });

        reader.fromJsonArray<Course>(root.value("courses").toArray(), [&](Course* course) {
            courseRepo.insert(course);
        });
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
            JsonWriter writer;

            writer["locations"] = writer.toJsonArray(locationRepo.getAll());
            writer["doctors"] = writer.toJsonArray(doctorRepo.getAll());
            writer["tas"] = writer.toJsonArray(taRepo.getAll());
            writer["courses"] = writer.toJsonArray(courseRepo.getAll());

            f.write(QJsonDocument(writer.object()).toJson());
        }
    }
}

