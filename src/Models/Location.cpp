#include "Location.h"

namespace Lumen {
    Location::Location() : m_id(QUuid::createUuid()) {}

    Location::Location(const QString& name, const QString& description)
        : m_id(QUuid::createUuid()), m_name(name), m_description(description) {}

    Location::Location(const QUuid& id, const QString& name, const QString& description)
        : m_id(id), m_name(name), m_description(description) {}

    QUuid Location::id() const {
        return m_id;
    }

    QString Location::name() const {
        return m_name;
    }

    QString Location::description() const {
        return m_description;
    }

    void Location::setName(const QString& name) {
        m_name = name;
    }

    void Location::setDescription(const QString& description) {
        m_description = description;
    }

    QJsonValue Lumen::Location::toJson() const {
        QJsonObject json;

        json["id"] = m_id.toString();
        json["name"] = m_name;
        json["description"] = m_description;

        return json;
    }

    void Location::fromJson(JsonReader& reader, const QJsonValue& json) {
        Q_ASSERT(json.isObject());

        QJsonObject obj = json.toObject();

        Q_ASSERT(obj.contains("id"));
        Q_ASSERT(obj.contains("name"));
        Q_ASSERT(obj.contains("description"));

        m_id = QUuid::fromString(obj.value("id").toString());
        m_name = obj.value("name").toString();
        m_description = obj.value("description").toString();

        reader.registerObject(m_id, this);
    }
}

