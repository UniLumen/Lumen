#pragma once

#include <QtCore>

#include "JsonSerializable.h"

namespace Lumen {
    class Location : public JsonSerializable {
    public:
        Location();
        Location(const QString& name, const QString& building, int floor, const QString& description);
        Location(const QUuid& id, const QString& name, const QString& building,int floor, const QString& description);

        QUuid id() const;
        QString name() const;
        QString building() const;
        int floor() const;
        QString description() const;

        void setName(const QString& name);
        void setBuilding(const QString& building);
        void setFloor(int floor);
        void setDescription(const QString& description);

        QJsonValue toJson() const override;
        void fromJson(JsonReader& reader, const QJsonValue& json) override;

        inline bool operator==(const Location& other) const {
            return m_name == other.m_name;
        }

        inline bool operator!=(const Location& other) const {
            return !(*this == other);
        }

    private:
        QUuid m_id;
        QString m_name;
        QString m_building;
        int m_floor;
        QString m_description;
    };
}

