#pragma once

#include <QAbstractListModel>

#include "Models/Location.h"

using namespace Lumen;

class LocationListView : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles{
        Name = Qt::UserRole,
        Building,
        Floor
    };

    LocationListView(QObject* parent = nullptr);
    LocationListView(const QList<Location*>& locations);
    LocationListView(const QList<const Location*>& locations);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public:
    void setLocations(const QList<const Location*>& locations);

public slots:
    void addLocation(const Location* location);
    const Location* removeLocation(int index);

signals:
    void createLocationRequest(const QString& name, const QString& building, int floor, const QString& description);
    void removeLocationRequest(int index);

private:
    QList<const Location*> m_locations;
};
