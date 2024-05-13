#pragma once

#include "Course.h"
#include "JsonSerializable.h"

namespace Lumen {
    class CourseAttendance : public ICourse, public JsonSerializable {
    public:
        CourseAttendance() = default;
        CourseAttendance(const Course* course, unsigned int attendance);

        const Course* course() const;

        QUuid id() const override;
        QString name() const override;
        QString code() const override;
        int creditHours() const override;
        bool hasLecture() const override;
        bool hasLab() const override;
        bool hasTutorial() const override;
        QList<Lecture> lectures() const override;
        QList<Section> sections() const override;
        QList<const Instructor*> doctors() const override;

        void setName(const QString& name) override;
        void setCode(const QString& code) override;
        bool setCreditHours(int creditHours) override;
        void setCourseComponents(unsigned int components) override;

        QJsonValue toJson() const override;
        void fromJson(JsonReader& reader, const QJsonValue& json) override;

        inline bool operator==(const CourseAttendance& other) const {
            return m_course == other.m_course;
        }

        inline bool operator!=(const CourseAttendance& other) const {
            return !(*this == other);
        }

    private:
        const Course* m_course = nullptr;
        unsigned int m_attendance = 0;
    };
}
