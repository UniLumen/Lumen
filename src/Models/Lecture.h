#pragma once

#include <QtCore>

#include "Location.h"

namespace Lumen {
    class Lecture : public JsonSerializable {
    public:
        Lecture() = default;
        Lecture(int group, const QDateTime& dateTime, const Location* location);

        int group() const;
        QDateTime dateTime() const;
        const Location* location() const;

        int setGroup(int group);
        void setDateTime(const QDateTime& dateTime);
        void setLocation(const Location* location);

        QJsonValue toJson() const override;
        void fromJson(JsonReader& reader, const QJsonValue& json) override;

        inline bool operator==(const Lecture& other) const {
            return m_group == other.m_group && m_dateTime == other.m_dateTime && m_location == other.m_location;
        }

        inline bool operator!=(const Lecture& other) const {
            return !(*this == other);
        }

    private:
        int m_group;
        QDateTime m_dateTime;
        const Location* m_location;
    };
}

