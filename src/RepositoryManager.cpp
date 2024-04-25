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

        reader.fromJsonObject(root.value("locations").toObject(), &locationRepo);
        reader.fromJsonObject(root.value("doctors").toObject(), &doctorRepo);
        reader.fromJsonObject(root.value("tas").toObject(), &taRepo);
        reader.fromJsonObject(root.value("courses").toObject(), &courseRepo);
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

            writer["locations"] = writer.toJsonObject(&locationRepo);
            writer["doctors"] = writer.toJsonObject(&doctorRepo);
            writer["tas"] = writer.toJsonObject(&taRepo);
            writer["courses"] = writer.toJsonObject(&courseRepo);

            f.write(QJsonDocument(writer.object()).toJson());
        }
    }
}

