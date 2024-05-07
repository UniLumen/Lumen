#pragma once

#include <QtCore>
#include <algorithm>

#include "JsonSerializable.h"

#include "Doctor.h"
#include "Lecture.h"
#include "Section.h"

namespace Lumen {
    class Course : public JsonSerializable {
    public:
        Course();
        Course(const QString& name, const QString& code, int creditHours);
        Course(const QUuid& id, const QString& name, const QString& code, int creditHours);

        QUuid id() const;
        QString name() const;
        QString code() const;
        int creditHours() const;
        QList<Lecture> lectures() const;
        QList<Section> sections() const;
        QList<const Doctor*> doctors() const;

        void setName(const QString& name);
        void setCode(const QString& code);
        bool setCreditHours(int creditHours);

        QJsonValue toJson() const override;
        void fromJson(JsonReader& reader, const QJsonValue& json) override;

        inline bool operator==(const Course& other) const {
            return m_name == other.m_name && m_code == other.m_code && m_creditHours == other.m_creditHours &&
                   std::equal(m_lectures.cbegin(), m_lectures.cend(), other.m_lectures.cbegin()) &&
                   std::equal(m_sections.cbegin(), m_sections.cend(), other.m_sections.cbegin()) &&
                   std::equal(m_doctors.cbegin(), m_doctors.cend(), other.m_doctors.cbegin());
        }

        inline bool operator!=(const Course& other) const {
            return !(*this == other);
        }

    private:
        QUuid m_id;
        QString m_name;
        QString m_code;
        int m_creditHours;
        QVector<Lecture> m_lectures;
        QVector<Section> m_sections;
        QVector<const Doctor*> m_doctors;
    };
}

