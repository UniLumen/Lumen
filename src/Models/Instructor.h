#pragma once

#include <QtCore>

#include "JsonSerializable.h"

namespace Lumen {
class Instructor : public JsonSerializable {
public:
    Instructor();
    Instructor(const QString& name, const QString& email, const bool isDoc);
    Instructor(const QUuid& id, const QString& name, const QString& email, const bool isDoc);

    QUuid id() const;
    QString name() const;
    QString email() const;
    bool isDoc() const;

    void setName(const QString& name);
    bool setEmail(const QString& email);

    QJsonValue toJson() const override;
    void fromJson(JsonReader& reader, const QJsonValue& json) override;

    inline bool operator==(const Instructor& other) const {
        return m_name == other.m_name && m_email == other.m_email;
    }

    inline bool operator!=(const Instructor& other) const {
        return !(*this == other);
    }

private:
    QUuid m_id;
    QString m_name;
    QString m_email;
    bool m_isDoc;
};
}


