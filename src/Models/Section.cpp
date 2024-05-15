#include "Section.h"

namespace Lumen {
    Section::Section(int number, const QDateTime& dateTime, const Location* location, const Instructor* ta)
        : m_number(number), m_dateTime(dateTime), m_location(location), m_ta(ta) {}

    int Section::number() const {
        return m_number;
    }

    QDateTime Section::dateTime() const {
        return m_dateTime;
    }

    const Location* Section::location() const {
        return m_location;
    }

    const Instructor* Section::ta() const {
        return m_ta;
    }

    bool Section::setNumber(int number) {
        if (number <= 0) {
            return false;
        }

        m_number = number;
        return true;
    }

    void Section::setDateTime(const QDateTime& dateTime) {
        m_dateTime = dateTime;
    }

    void Section::setLocation(const Location* location) {
        m_location = location;
    }

    void Section::setTa(const Instructor* ta) {
        m_ta = ta;
    }

    QJsonValue Section::toJson() const {
        QJsonObject json;

        json["number"] = m_number;
        json["dateTime"] = m_dateTime.toString();
        json["locationId"] = m_location->id().toString();
        json["taId"] = m_ta->id().toString();

        return json;
    }

    void Section::fromJson(JsonReader& reader, const QJsonValue& json) {
        Q_ASSERT(json.isObject());

        QJsonObject obj = json.toObject();

        Q_ASSERT(obj.contains("number"));
        Q_ASSERT(obj.contains("dateTime"));

        m_number = obj.value("number").toInt();
        m_dateTime = QDateTime::fromString(obj.value("dateTime").toString());

        if (obj.contains("locationId")) {
            QUuid locationId(obj.value("locationId").toString());
            Q_ASSERT(reader.contains(locationId));
            if (reader.contains(locationId)) {
                m_location = reader.get<Location>(locationId);
            }
        }

        if (obj.contains("taId")) {
            QUuid taId(obj.value("taId").toString());
            Q_ASSERT(reader.contains(taId));
            if (reader.contains(taId)) {
                m_ta = reader.get<Instructor>(taId);
            }
        }
    }
}

