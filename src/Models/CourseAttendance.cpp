#include "CourseAttendance.h"
#include "RepositoryManager.h"

namespace Lumen {
    CourseAttendance::CourseAttendance(const Course* course, unsigned int attendance)
        : m_course(course), m_attendance(attendance) {}

    const Course* CourseAttendance::course() const {
        return m_course;
    }

    QUuid CourseAttendance::id() const {
        Q_ASSERT(m_course);
        return m_course->id();
    }

    QString CourseAttendance::name() const {
        Q_ASSERT(m_course);
        return m_course->name();
    }

    QString CourseAttendance::code() const {
        Q_ASSERT(m_course);
        return m_course->code();
    }

    QString CourseAttendance::dept() const {
        Q_ASSERT(m_course);
        return m_course->dept();
    }

    int CourseAttendance::year() const {
        Q_ASSERT(m_course);
        return m_course->year();
    }

    int CourseAttendance::creditHours() const {
        Q_ASSERT(m_course);
        return m_course->creditHours();
    }

    bool CourseAttendance::hasLecture() const {
        return (m_attendance & Course::LectureComponent);
    }

    bool CourseAttendance::hasLab() const {
        return (m_attendance & Course::LabComponent);
    }

    bool CourseAttendance::hasTutorial() const {
        return (m_attendance & Course::TutorialComponent);
    }

    bool CourseAttendance::hasMandatoryLecture() const {
        Q_ASSERT(m_course);
        return m_course->hasMandatoryLecture();
    }

    bool CourseAttendance::hasMandatoryLab() const {
        Q_ASSERT(m_course);
        return m_course->hasMandatoryLab();
    }

    bool CourseAttendance::hasMandatoryTutorial() const {
        Q_ASSERT(m_course);
        return m_course->hasMandatoryTutorial();
    }

    QList<Lecture> CourseAttendance::lectures() const {
        Q_ASSERT(m_course);
        return m_course->lectures();
    }

    QList<Section> CourseAttendance::sections() const {
        Q_ASSERT(m_course);
        return m_course->sections();
    }

    QList<const Instructor*> CourseAttendance::doctors() const {
        Q_ASSERT(m_course);
        return m_course->doctors();
    }

    void CourseAttendance::setName(const QString& name) {}

    void CourseAttendance::setCode(const QString& code) {}

    void CourseAttendance::setDept(const QString& dept) {}

    void CourseAttendance::setYear(int year) {}

    bool CourseAttendance::setCreditHours(int creditHours) {
        return false;
    }

    void CourseAttendance::setCourseComponents(unsigned int components) {
        m_attendance = components;
    }

    void CourseAttendance::setMandatoryComponents(unsigned int components) {}

    QJsonValue CourseAttendance::toJson() const {
        QJsonObject json;

        json["courseId"] = m_course->id().toString();
        json["attendLecture"] = hasLecture();
        json["attendLab"] = hasLab();
        json["attendTutorial"] = hasTutorial();

        return json;
    }

    void CourseAttendance::fromJson(JsonReader& reader, const QJsonValue& json) {
        Q_ASSERT(json.isObject());

        QJsonObject obj = json.toObject();

        Q_ASSERT(obj.contains("courseId"));
        Q_ASSERT(obj.contains("attendLecture"));
        Q_ASSERT(obj.contains("attendLab"));
        Q_ASSERT(obj.contains("attendTutorial"));

        QUuid id = QUuid::fromString(obj.value("courseId").toString());
        RepositoryManager& repoManager = RepositoryManager::instance();

        m_course = (repoManager.courseRepo.contains(id)) ? repoManager.courseRepo.get(id) : nullptr;
        if (obj.value("attendLecture").toBool()) {
            m_attendance |= Course::LectureComponent;
        }
        if (obj.value("attendLab").toBool()) {
            m_attendance |= Course::LabComponent;
        }
        if (obj.value("attendTutorial").toBool()) {
            m_attendance |= Course::TutorialComponent;
        }
    }
}
