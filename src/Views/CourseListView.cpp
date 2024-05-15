#include "CourseListView.h"

CourseListView::CourseListView(QObject* parent) : QAbstractListModel(parent) {}

CourseListView::CourseListView(const QList<ICourse*>& courses, QObject* parent) : QAbstractListModel(parent) {
    for (const auto& c : courses) {
        m_courses.push_back(c);
    }

    validate();
}

CourseListView::CourseListView(const QList<const ICourse*>& courses, QObject* parent)
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

    const ICourse* course = m_courses.at(index.row());
    switch (role) {
        case IdRole:
            return course->id();
        case TitleRole:
            return course->name();
        case CodeRole:
            return course->code();
        case CreditHours:
            return course->creditHours();
        case HasLecture:
            return course->hasLecture();
        case HasLab:
            return course->hasLab();
        case HasTutorial:
            return course->hasTutorial();
        case HasMandatoryLecture:
            return course->hasMandatoryLecture();
        case HasMandatoryLab:
            return course->hasMandatoryLab();
        case HasMandatoryTutorial:
            return course->hasMandatoryTutorial();
    }

    return QVariant();
}

QHash<int, QByteArray> CourseListView::roleNames() const {
    static QHash<int, QByteArray> mapping {
        {              IdRole,                   "id"},
        {           TitleRole,                "title"},
        {            CodeRole,                 "code"},
        {         CreditHours,          "creditHours"},
        {          HasLecture,           "hasLecture"},
        {              HasLab,               "hasLab"},
        {         HasTutorial,          "hasTutorial"},
        { HasMandatoryLecture,  "hasMandatoryLecture"},
        {     HasMandatoryLab,      "hasMandatoryLab"},
        {HasMandatoryTutorial, "hasMandatoryTutorial"}
    };

    return mapping;
}

void CourseListView::setCourses(const QList<const ICourse*>& courses) {
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

void CourseListView::addCourse(const ICourse* course) {
    int index = m_courses.count();

    beginInsertRows(QModelIndex(), index, index);
    m_courses.push_back(course);
    endInsertRows();

    emit creditHoursChanged();
    validate();
}

void CourseListView::createCourse(const QVariantMap& courseMap) {
    CourseCreationDTO dto = {};

    dto.name = courseMap["name"].toString();
    dto.code = courseMap["code"].toString();
    dto.dept = courseMap["dept"].toString();
    dto.year = courseMap["year"].toInt();
    dto.creditHours = courseMap["creditHours"].toInt();
    dto.hasLecture = courseMap["hasLecture"].toBool();
    dto.hasLab = courseMap["hasLab"].toBool();
    dto.hasTutorial = courseMap["hasTutorial"].toBool();
    dto.hasMandatoryLecture = courseMap["isLectureMandatory"].toBool();
    dto.hasMandatoryLab = courseMap["isLabMandatory"].toBool();
    dto.hasMandatoryTutorial = courseMap["isTutorialMandatory"].toBool();

    emit createCourseRequest(dto);
}

const ICourse* CourseListView::removeCourse(int index) {
    if (index < 0 || index >= m_courses.count()) {
        return nullptr;
    }

    const ICourse* course = m_courses.at(index);

    beginRemoveRows(QModelIndex(), index, index);
    m_courses.removeAt(index);
    endRemoveRows();

    emit creditHoursChanged();
    validate();

    return course;
}

const ICourse* CourseListView::removeCourse(const ICourse* course) {
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

QVariantMap CourseListView::getCourseMap(int index) const {
    QVariantMap dataMap;

    const QModelIndex idx = this->index(index, 0);
    if (!idx.isValid()) {
        return dataMap;
    }

    const QHash<int, QByteArray> rn = roleNames();
    for (auto i : rn.keys()) {
        dataMap[rn.value(i)] = data(idx, i);
    }

    return dataMap;
}
