#include "LocationModel.h"

LocationModel::LocationModel(QObject *parent):
    QAbstractListModel(parent){

    Location l1 ("said abdelwahab", "FCIS", 3, "description");
    Location l2 ("said abdelwahab", "FCIS", 3, "description");
    Location l3 ("said abdelwahab", "FCIS", 3, "description");

    m_data.push_back(l1);
    m_data.push_back(l2);
    m_data.push_back(l3);
}

int LocationModel::rowCount(const QModelIndex &parent) const{
    if(parent.isValid()){
        return 0;
    }

    return m_data.size();
}

QVariant LocationModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()){
        return QVariant();
    }

    const Location &data = m_data.at(index.row());

    switch(role){
    case Roles::Name: return data.name;
    case Roles::Floor: return data.floor;
    case Roles::Building: return data.building;
    default: return QVariant();
    }
}

QHash<int, QByteArray> LocationModel::roleNames() const{
    QHash<int, QByteArray> mapping{
        {Roles::Name, "name"},
        {Roles::Floor, "floor"},
        {Roles::Building, "building"}
    };

    return mapping;
}

void LocationModel::onRemoveLocation(int index){
    beginRemoveRows(QModelIndex(), index,index);
    m_data.erase(m_data.begin()+index);
    qDebug() << "onRemove Location called on index: " + std::to_string(index);
    endRemoveRows();
}

void LocationModel::onAddLocation(QString name, QString building, QString floor, QString description){
    beginInsertRows(QModelIndex(),m_data.size(), m_data.size());
    m_data.push_back(Location(name, building, floor.toInt(), description));
    endInsertRows();
    qDebug() << "adding location: " + name + " " + building + " " + floor + " " + description;

}
