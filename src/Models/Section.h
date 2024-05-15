#pragma once

#include <QtCore>

#include "Location.h"
#include "Instructor.h"

namespace Lumen {
    class Section : public JsonSerializable {
    public:
        Section() = default;
        Section(int number, const QDateTime& dateTime, const Location* location, const Instructor* ta);

        int number() const;
        QDateTime dateTime() const;
        const Location* location() const;
        const Instructor* ta() const;

        bool setNumber(int number);
        void setDateTime(const QDateTime& dateTime);
        void setLocation(const Location* location);
        void setTa(const Instructor* ta);

        QJsonValue toJson() const override;
        void fromJson(JsonReader& reader, const QJsonValue& json) override;

        inline bool operator==(const Section& other) const {
            return m_number == other.m_number && m_dateTime == other.m_dateTime && m_location == other.m_location &&
                   m_ta == other.m_ta;
        }

        inline bool operator!=(const Section& other) const {
            return !(*this == other);
        }

    private:
        int m_number;
        QDateTime m_dateTime;
        const Location* m_location;
        const Instructor* m_ta;
    };
}

