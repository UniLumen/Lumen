#ifndef LOCATIONMODEL_H
#define LOCATIONMODEL_H

#include <QAbstractListModel>
#include "Models/Location.h"
#include "RepositoryManager.h"

class LocationModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles{
        Name = Qt::UserRole,
        Building,
        Floor
    };

    LocationModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void onAddLocation(QString name, QString building, QString floor, QString description);
    void onRemoveLocation(int index);

private:
    QList<Lumen::Location*> m_data;
    Lumen::RepositoryManager& repoManager = Lumen::RepositoryManager::instance();
};
#endif // LOCATIONMODEL_H
