#pragma once

#include <QtCore>
#include <algorithm>

#include "JsonSerializable.h"

#include "ICourse.h"
#include "Instructor.h"
#include "Lecture.h"
#include "Section.h"

namespace Lumen {
    class Course : public ICourse, public JsonSerializable {
    public:
        enum CourseComponents {
            LectureComponent = 1 << 0,
            LabComponent = 1 << 1,
            TutorialComponent = 1 << 2
        };

        Course();
        Course(const QString& name, const QString& code, int creditHours, unsigned int courseComponents = LectureComponent);
        Course(const QUuid& id, const QString& name, const QString& code, int creditHours,
               unsigned int courseComponents = LectureComponent);
        Course(const QString& name, int year,const QString& dept, int creditHours, unsigned int courseComponents = LectureComponent);


        QUuid id() const override;
        QString name() const override;
        QString code() const override;
        int creditHours() const override;
        int yearOfStudy() const;
        QString department() const;
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
        QString m_dept;
        int m_year;
        int m_creditHours = 0;
        unsigned int m_courseComponents = 0;
        QVector<Lecture> m_lectures;
        QVector<Section> m_sections;
        QVector<const Instructor*> m_doctors;
    };
}

