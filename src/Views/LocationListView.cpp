#include "LocationListView.h"

LocationListView::LocationListView(QObject* parent) : QAbstractListModel(parent) {}

LocationListView::LocationListView(const QList<Location*>& locations) {
    for (const auto& l : locations) {
        m_locations.push_back(l);
    }
}

LocationListView::LocationListView(const QList<const Location*>& locations) : m_locations(locations) {}

int LocationListView::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }

    return m_locations.size();
}

QVariant LocationListView::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    const Location* data = m_locations.at(index.row());

    switch (role) {
        case Roles::Name:
            return data->name();
        case Roles::Floor:
            return data->floor();
        case Roles::Building:
            return data->building();
    }

    return QVariant();
}

QHash<int, QByteArray> LocationListView::roleNames() const {
    QHash<int, QByteArray> mapping {
        {    Roles::Name,     "name"},
        {   Roles::Floor,    "floor"},
        {Roles::Building, "building"}
    };

    return mapping;
}

void LocationListView::setLocations(const QList<const Location*>& locations) {
    beginResetModel();
    m_locations.clear();
    for (const auto& l : locations) {
        m_locations.push_back(l);
    }
    endResetModel();
}

void LocationListView::addLocation(const Location* location) {
    beginInsertRows(QModelIndex(), m_locations.size(), m_locations.size());
    m_locations.push_back(location);
    endInsertRows();
}

const Location* LocationListView::removeLocation(int index) {
    if (index < 0 || index >= m_locations.count()) {
        return nullptr;
    }

    const Location* removedLocation = m_locations.at(index);

    beginRemoveRows(QModelIndex(), index, index);
    m_locations.remove(index);
    endRemoveRows();

    return removedLocation;
}
