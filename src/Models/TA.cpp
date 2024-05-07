#include "TA.h"

#include <regex>

namespace Lumen {
    TA::TA() : m_id(QUuid::createUuid()) {}

    TA::TA(const QString& name, const QString& email) : m_id(QUuid::createUuid()), m_name(name) {
        setEmail(email);
    }

    TA::TA(const QUuid& id, const QString& name, const QString& email) : m_id(id), m_name(name) {
        setEmail(email);
    }

    QUuid TA::id() const {
        return m_id;
    }

    QString TA::name() const {
        return m_name;
    }

    QString TA::email() const {
        return m_email;
    }

    void TA::setName(const QString& name) {
        m_name = name;
    }

    bool TA::setEmail(const QString& email) {
        const std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        if (std::regex_match(email.toStdString(), pattern)) {
            m_email = email;
            return true;
        }

        return false;
    }

    QJsonValue Lumen::TA::toJson() const {
        QJsonObject json;

        json["id"] = m_id.toString();
        json["name"] = m_name;
        json["email"] = m_email;

        return json;
    }

    void Lumen::TA::fromJson(JsonReader& reader, const QJsonValue& json) {
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

