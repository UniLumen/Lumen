#include "Lecture.h"

namespace Lumen {
    Lecture::Lecture(int group, const QDateTime& dateTime, const Location* location)
        : m_group(group), m_dateTime(dateTime), m_location(location) {}

    int Lecture::group() const {
        return m_group;
    }

    QDateTime Lecture::dateTime() const {
        return m_dateTime;
    }

    const Location* Lecture::location() const {
        return m_location;
    }

    QJsonValue Lecture::toJson() const {
        QJsonObject json;

        json["group"] = m_group;
        json["dateTime"] = m_dateTime.toString();
        json["locationId"] = m_location->id().toString();

        return json;
    }

    void Lecture::fromJson(JsonReader& reader, const QJsonValue& json) {
        Q_ASSERT(json.isObject());

        QJsonObject obj = json.toObject();

        Q_ASSERT(obj.contains("group"));
        Q_ASSERT(obj.contains("dateTime"));

        m_group = obj.value("group").toInt();
        m_dateTime = QDateTime::fromString(obj.value("dateTime").toString());

        if (obj.contains("locationId")) {
            QUuid locationId(obj.value("locationId").toString());
            Q_ASSERT(reader.contains(locationId));
            m_location = reader.get<Location>(locationId);
        }
    }
}

