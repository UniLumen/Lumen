#pragma once

#include <QtCore>

#include "JsonSerializable.h"

namespace Lumen {
    class Location : public JsonSerializable {
    public:
        Location();
        Location(const QString& name, const QString& description);
        Location(const QUuid& id, const QString& name, const QString& description);

        QUuid id() const;
        QString name() const;
        QString description() const;

        void setName(const QString& name);
        void setDescription(const QString& description);

        QJsonValue toJson() const override;
        void fromJson(JsonReader& reader, const QJsonValue& json) override;

        inline bool operator==(const Location& other) const {
            return m_name == other.m_name && m_description == other.m_description;
        }

        inline bool operator!=(const Location& other) const {
            return !(*this == other);
        }

    private:
        QUuid m_id;
        QString m_name;
        QString m_description;
    };
}

