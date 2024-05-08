#include "CourseListView.h"

CourseListView::CourseListView(QObject* parent) : QAbstractListModel(parent) {}

CourseListView::CourseListView(const QList<Course*>& courses, QObject* parent) : QAbstractListModel(parent) {
    for (const auto& c : courses) {
        m_courses.push_back(c);
    }

    validate();
}

CourseListView::CourseListView(const QList<const Course*>& courses, QObject* parent)
    : QAbstractListModel(parent), m_courses(courses) {
    validate();
}

int CourseListView::rowCount(const QModelIndex& parent) const {
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) {
        return 0;
    }

    return m_courses.count();
}

QVariant CourseListView::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= m_courses.size() || index.row() < 0) {
        return QVariant();
    }

    const Course* course = m_courses.at(index.row());
    switch (role) {
        case IdRole:
            return course->id();
        case TitleRole:
            return course->name();
        case CodeRole:
            return course->code();
        case CreditHours:
            return course->creditHours();
    }

    return QVariant();
}

QHash<int, QByteArray> CourseListView::roleNames() const {
    static QHash<int, QByteArray> mapping {
        {     IdRole,          "id"},
        {  TitleRole,       "title"},
        {   CodeRole,        "code"},
        {CreditHours, "creditHours"}
    };

    return mapping;
}

void CourseListView::setCourses(const QList<Course*>& courses) {
    beginResetModel();
    m_courses.clear();
    for (const auto& c : courses) {
        m_courses.push_back(c);
    }
    endResetModel();

    emit creditHoursChanged();
    validate();
}

void CourseListView::setMinCreditHours(int minCreditHours) {
    m_minCreditHours = minCreditHours;
    validate();

    emit creditHoursChanged();
}

void CourseListView::setMaxCreditHours(int maxCreditHours) {
    m_maxCreditHours = maxCreditHours;
    validate();

    emit creditHoursChanged();
}

void CourseListView::addCourse(const Course* course) {
    int index = m_courses.count();

    beginInsertRows(QModelIndex(), index, index);
    m_courses.push_back(course);
    endInsertRows();

    emit creditHoursChanged();
    validate();
}

const Course* CourseListView::removeCourse(int index) {
    if (index < 0 || index >= m_courses.count()) {
        return nullptr;
    }

    const Course* course = m_courses.at(index);

    beginRemoveRows(QModelIndex(), index, index);
    m_courses.removeAt(index);
    endRemoveRows();

    emit creditHoursChanged();
    validate();

    return course;
}

const Course* CourseListView::removeCourse(const Course* course) {
    int index = m_courses.indexOf(course);
    return removeCourse(index);
}

int CourseListView::creditHours() const {
    int hours = 0;
    for (const auto& c : m_courses) {
        hours += c->creditHours();
    }

    return hours;
}

void CourseListView::validate() {
    int cHours = creditHours();
    bool error = (cHours > m_maxCreditHours) || (cHours < m_minCreditHours);
    m_error.clear();
    m_note.clear();

    if (error) {
        m_error += "<ul>";
        if (cHours < m_minCreditHours) {
            m_error += "<li>Credit hours is not sufficent</li>";
        }
        if (cHours > m_maxCreditHours) {
            m_error += "<li>Exceeds max credit hours</li>";
        }
        m_error += "</ul>";
    } else {
        m_note = "<ul>";
        if (cHours > 18) {
            m_note += "<li>Requires GPA >= 3</li>";
        } else if (cHours > 14) {
            m_note += "<li>Requires GPA >= 2</li>";
        }
        m_note += "</ul>";
    }

    emit postValidation();
}

