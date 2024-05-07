#include "Doctor.h"

#include <regex>

namespace Lumen {
    Doctor::Doctor() : m_id(QUuid::createUuid()) {}

    Doctor::Doctor(const QString& name, const QString& email) : m_name(name) {
        setEmail(email);
    }

    Doctor::Doctor(const QUuid& id, const QString& name, const QString& email) : m_id(id), m_name(name) {
        setEmail(email);
    }

    QUuid Doctor::id() const {
        return m_id;
    }

    QString Doctor::name() const {
        return m_name;
    }

    QString Doctor::email() const {
        return m_email;
    }

    void Doctor::setName(const QString& name) {
        m_name = name;
    }

    bool Doctor::setEmail(const QString& email) {
        const std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        if (std::regex_match(email.toStdString(), pattern)) {
            m_email = email;
            return true;
        }

        return false;
    }

    QJsonValue Doctor::toJson() const {
        QJsonObject json;

        json["id"] = m_id.toString();
        json["name"] = m_name;
        json["email"] = m_email;

        return json;
    }

    void Doctor::fromJson(JsonReader& reader, const QJsonValue& json) {
        Q_ASSERT(json.isObject());

        QJsonObject obj = json.toObject();

        Q_ASSERT(obj.contains("id"));
        Q_ASSERT(obj.contains("name"));
        Q_ASSERT(obj.contains("email"));

        m_id = QUuid::fromString(obj.value("id").toString());
        m_name = obj.value("name").toString();
        setEmail(obj.value("email").toString());

        reader.registerObject(m_id, this);
    }
}

