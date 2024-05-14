#include "Course.h"

namespace Lumen {
    Course::Course() : m_id(QUuid::createUuid()) {}

    Course::Course(const QString& name, const QString& code, int creditHours, unsigned int courseComponents)
        : m_id(QUuid::createUuid()), m_name(name), m_code(code), m_creditHours(creditHours), m_courseComponents(courseComponents) {}

    Course::Course(const QUuid& id, const QString& name, const QString& code, int creditHours, unsigned int courseComponents)
        : m_id(id), m_name(name), m_code(code), m_creditHours(creditHours), m_courseComponents(courseComponents) {}

    Course::Course(const QString& name, int year,const QString& dept, int creditHours, unsigned int courseComponents)
        : m_id(QUuid::createUuid()), m_name(name), m_year(year), m_dept(dept), m_creditHours(creditHours), m_courseComponents(courseComponents){}

    QUuid Course::id() const {
        return m_id;
    }

    QString Course::name() const {
        return m_name;
    }

    int Course::yearOfStudy() const{
        return m_year;
    }

    QString Course::department() const{
        return m_dept;
    }

    QString Course::code() const {
        return m_code;
    }

    int Course::creditHours() const {
        return m_creditHours;
    }

    bool Course::hasLecture() const {
        return (m_courseComponents & LectureComponent);
    }

    bool Course::hasLab() const {
        return (m_courseComponents & LabComponent);
    }

    bool Course::hasTutorial() const {
        return (m_courseComponents & TutorialComponent);
    }

    QList<Lecture> Course::lectures() const {
        return m_lectures;
    }

    QList<Section> Course::sections() const {
        return m_sections;
    }

    QList<const Instructor*> Course::doctors() const {
        return m_doctors;
    }

    void Course::setName(const QString& name) {
        m_name = name;
    }

    void Course::setCode(const QString& code) {
        m_code = code;
    }

    bool Course::setCreditHours(int creditHours) {
        if (creditHours < 0) {
            return false;
        }

        m_creditHours = creditHours;
        return true;
    }

    void Course::setCourseComponents(unsigned int components) {
        m_courseComponents = components;
    }

    QJsonValue Course::toJson() const {
        QJsonObject json;

        json["id"] = m_id.toString();
        json["name"] = m_name;
        json["code"] = m_code;
        json["creditHours"] = m_creditHours;
        json["yearOfStudy"] = m_year;
        json["dept"] = m_dept;
        json["hasLecture"] = hasLecture();
        json["hasLab"] = hasLab();
        json["hasTutorial"] = hasTutorial();

        {
            QJsonArray lecs;
            for (const auto& lec : m_lectures) {
                lecs.push_back(lec.toJson());
            }
            json["lectures"] = lecs;
        }

        {
            QJsonArray secs;
            for (const auto& sec : m_sections) {
                secs.push_back(sec.toJson());
            }
            json["sections"] = secs;
        }

        {
            QJsonArray docs;
            for (const auto& doc : m_doctors) {
                docs.push_back(doc->id().toString());
            }
            json["doctors"] = docs;
        }

        return json;
    }

    void Course::fromJson(JsonReader& reader, const QJsonValue& json) {
        Q_ASSERT(json.isObject());

        QJsonObject obj = json.toObject();

        Q_ASSERT(obj.contains("id"));
        Q_ASSERT(obj.contains("name"));
        Q_ASSERT(obj.contains("code"));
        Q_ASSERT(obj.contains("creditHours"));
        Q_ASSERT(obj.contains("yearOfStudy"));
        Q_ASSERT(obj.contains("dept"));
        Q_ASSERT(obj.contains("lectures"));
        Q_ASSERT(obj.contains("sections"));
        Q_ASSERT(obj.contains("doctors"));
        Q_ASSERT(obj.contains("hasLecture"));
        Q_ASSERT(obj.contains("hasLab"));
        Q_ASSERT(obj.contains("hasTutorial"));

        m_id = QUuid::fromString(obj.value("id").toString());
        m_name = obj.value("name").toString();
        m_code = obj.value("code").toString();
        m_creditHours = obj.value("creditHours").toInt();
        m_year = obj.value("yearOfStudy").toInt();
        m_dept = obj.value("dept").toString();

        if (obj.value("hasLecture").toBool()) {
            m_courseComponents |= LectureComponent;
        }
        if (obj.value("hasLab").toBool()) {
            m_courseComponents |= LabComponent;
        }
        if (obj.value("hasTutorial").toBool()) {
            m_courseComponents |= TutorialComponent;
        }

        {
            QJsonArray lecs = json["lectures"].toArray();
            m_lectures.reserve(lecs.count());
            for (const auto& lec : lecs) {
                Lecture l;
                l.fromJson(reader, lec);
                m_lectures.append(l);
            }
        }

        {
            QJsonArray secs = json["sections"].toArray();
            m_lectures.reserve(secs.count());
            for (const auto& sec : secs) {
                Section s;
                s.fromJson(reader, sec);
                m_sections.append(s);
            }
        }

        {
            QJsonArray docs = json["doctors"].toArray();
            m_doctors.reserve(docs.count());
            for (const auto& doc : docs) {
                QUuid doctorId(doc.toString());
                Q_ASSERT(reader.contains(doctorId));
                m_doctors.push_back(reader.get<Instructor>(doctorId));
            }
        }
    }
}

