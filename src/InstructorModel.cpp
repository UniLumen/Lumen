#include "InstructorModel.h"

InstructorModel::InstructorModel(QObject *parent):
    QAbstractListModel(parent){
    //TO DO: should load data from JSON

    Instructor i1 ("potato", "potato@gmai.com");
    Instructor i2 ("tomato", "tomato@gmai.com");
    Instructor i3 ("momento", "momento@gmai.com");

    m_data.push_back(i1);
    m_data.push_back(i2);
    m_data.push_back(i3);

}

int InstructorModel::rowCount(const QModelIndex &parent) const{
    if(parent.isValid()){
        return 0;
    }

    return m_data.size();
}

QVariant InstructorModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()){
        return QVariant();
    }

    const Instructor &data = m_data.at(index.row());

    switch(role){
    case Roles::Name: return data.name;
    case Roles::Email: return data.email;
    default: return QVariant();
    }
}

QHash<int, QByteArray> InstructorModel::roleNames() const{
    QHash<int, QByteArray> mapping{
        {Roles::Name, "name"},
        {Roles::Email, "email"},
    };

    return mapping;
}

void InstructorModel::onRemoveInstructor(int index){
    beginRemoveRows(QModelIndex(), index,index);
    m_data.erase(m_data.begin()+index);
    qDebug() << "onRemove instructor called on index: " + std::to_string(index);
    endRemoveRows();
}

void InstructorModel::onAddInstructor(QString name, QString email){
    beginInsertRows(QModelIndex(),m_data.size(), m_data.size());
    m_data.push_back(Instructor(name, email));
    endInsertRows();
    qDebug() << "adding instructor: " + name + " " + email;

}
