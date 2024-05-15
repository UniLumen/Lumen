#include "InstructorListView.h"

using namespace Lumen;

InstructorListView::InstructorListView(QObject* parent) : QAbstractListModel(parent) {}

InstructorListView::InstructorListView(const QList<Instructor*>& instructors) {
    for (const auto& i : instructors) {
        m_instructors.push_back(i);
    }
}

InstructorListView::InstructorListView(const QList<const Instructor*>& instructors) : m_instructors(instructors) {}

int InstructorListView::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }

    return m_instructors.size();
}

QVariant InstructorListView::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    const Instructor* data = m_instructors.at(index.row());

    switch (role) {
        case Roles::Name:
            return data->name();
        case Roles::Email:
            return data->email();
        case Roles::IsDoc:
            return data->isDoc();
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> InstructorListView::roleNames() const {
    QHash<int, QByteArray> mapping {
        { Roles::Name,  "name"},
        {Roles::Email, "email"},
        {Roles::IsDoc, "isDoc"}
    };

    return mapping;
}

void InstructorListView::setInstructors(const QList<const Instructor*>& instructors) {
    beginResetModel();
    m_instructors.clear();
    for (const auto& i : instructors) {
        m_instructors.push_back(i);
    }
    endResetModel();
}

void InstructorListView::addInstructor(const Instructor* instructor) {
    beginInsertRows(QModelIndex(), m_instructors.size(), m_instructors.size());
    m_instructors.push_back(instructor);
    endInsertRows();
}

const Instructor* InstructorListView::removeInstructor(int index) {
    const Instructor* removedLocation = m_instructors.at(index);

    beginRemoveRows(QModelIndex(), index, index);
    m_instructors.remove(index);
    endRemoveRows();

    return removedLocation;
}
