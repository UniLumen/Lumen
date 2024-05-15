#pragma once

#include <QAbstractListModel>

#include "DTOs/CourseCreationDTO.h"
#include "Models/Course.h"

using namespace Lumen;

class CourseListView : public QAbstractListModel {
    Q_OBJECT

    Q_PROPERTY(int creditHours READ creditHours NOTIFY creditHoursChanged FINAL)
    Q_PROPERTY(int minCreditHours MEMBER m_minCreditHours WRITE setMinCreditHours NOTIFY creditHoursChanged FINAL)
    Q_PROPERTY(int maxCreditHours MEMBER m_maxCreditHours WRITE setMaxCreditHours NOTIFY creditHoursChanged FINAL)
    Q_PROPERTY(QString error MEMBER m_error NOTIFY postValidation FINAL)
    Q_PROPERTY(QString note MEMBER m_note NOTIFY postValidation FINAL)

public:
    enum Roles {
        IdRole = Qt::UserRole,
        TitleRole,
        CodeRole,
        CreditHours,
        HasLecture,
        HasLab,
        HasTutorial,
        HasMandatoryLecture,
        HasMandatoryLab,
        HasMandatoryTutorial
    };

    explicit CourseListView(QObject* parent = nullptr);
    CourseListView(const QList<ICourse*>& courses, QObject* parent = nullptr);
    CourseListView(const QList<const ICourse*>& courses, QObject* parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int creditHours() const;

    void setCourses(const QList<const ICourse*>& courses);
    void setMinCreditHours(int minCreditHours);
    void setMaxCreditHours(int maxCreditHours);

public slots:
    void addCourse(const ICourse* course);
    void createCourse(const QVariantMap& courseMap);
    const ICourse* removeCourse(int index);
    const ICourse* removeCourse(const ICourse* course);
    QVariantMap getCourseMap(int index) const;

signals:
    void addCourseRequest(const QUuid& id);
    void addCourseAttendanceRequest(const QUuid& id, bool lecture, bool lab, bool tutorial);
    void removeCourseRequest(int index);
    void createCourseRequest(const CourseCreationDTO& creationDTO);

    void creditHoursChanged();
    void postValidation();

private:
    void validate();

private:
    QList<const ICourse*> m_courses;
    int m_minCreditHours = 0;
    int m_maxCreditHours = 1;
    QString m_error;
    QString m_note;
};

