#include "Instructor.h"

#include <regex>

namespace Lumen {
Instructor::Instructor() : m_id(QUuid::createUuid()) {}

Instructor::Instructor(const QString& name, const QString& email, const bool isDoc)
    : m_id(QUuid::createUuid()), m_name(name), m_isDoc(isDoc) {
    setEmail(email);
}

Instructor::Instructor(const QUuid& id, const QString& name, const QString& email, const bool isDoc)
    : m_id(id), m_name(name), m_isDoc(isDoc) {
    setEmail(email);
}

QUuid Instructor::id() const {
    return m_id;
}

QString Instructor::name() const {
    return m_name;
}

QString Instructor::email() const {
    return m_email;
}

bool Instructor::isDoc() const {
    return m_isDoc;
}

void Instructor::setName(const QString& name) {
    m_name = name;
}

bool Instructor::setEmail(const QString& email) {
    const std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (std::regex_match(email.toStdString(), pattern)) {
        m_email = email;
        return true;
    }

    return false;
}

void Instructor::setAsDoc(bool doc) {
    m_isDoc = doc;
}

QJsonValue Lumen::Instructor::toJson() const {
    QJsonObject json;

    json["id"] = m_id.toString();
    json["name"] = m_name;
    json["email"] = m_email;
    json["isDoc"] = m_isDoc;

    return json;
}

void Lumen::Instructor::fromJson(JsonReader& reader, const QJsonValue& json) {
    Q_ASSERT(json.isObject());

    QJsonObject obj = json.toObject();

    Q_ASSERT(obj.contains("id"));
    Q_ASSERT(obj.contains("name"));
    Q_ASSERT(obj.contains("email"));
    Q_ASSERT(obj.contains("isDoc"));


    m_id = QUuid::fromString(obj.value("id").toString());
    m_name = obj.value("name").toString();
    setEmail(obj.value("email").toString());
    m_isDoc = obj.value("isDoc").toBool();

    reader.registerObject(m_id, this);
}
}

