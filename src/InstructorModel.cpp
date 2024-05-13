#include "InstructorModel.h"

using namespace Lumen;
InstructorModel::InstructorModel(QObject *parent):
    QAbstractListModel(parent){
    const QList<Instructor*>& doctors= repoManager.doctorRepo.getAll();
    const QList<Instructor*>& tas= repoManager.taRepo.getAll();

    m_data.reserve(doctors.size() + tas.size());

    for(const auto& doctor : doctors){
        m_data.push_back(doctor);
    }

    for(const auto& ta : tas){
        m_data.push_back(ta);
    }

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

    const Instructor* data = m_data.at(index.row());

    switch(role){
    case Roles::Name: return data->name();
    case Roles::Email: return data->email();
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
    if(m_data[index]->isDoc()){
        repoManager.doctorRepo.remove(m_data[index]->id());
    }else{
        repoManager.taRepo.remove(m_data[index]->id());
    }
    m_data.erase(m_data.begin()+index);
    qDebug() << "onRemove instructor called on index: " + std::to_string(index);
    endRemoveRows();
}

void InstructorModel::onAddInstructor(QString name, QString email, bool isDoc){
    beginInsertRows(QModelIndex(),m_data.size(), m_data.size());
    Instructor* p_newInstructor = new Instructor(name, email, isDoc);
    if(!p_newInstructor->setEmail(email)){
        emit emailVerificationDone(p_newInstructor->setEmail(email));
    }
    if(isDoc){
        repoManager.doctorRepo.insert(p_newInstructor->id(), p_newInstructor);
    }else{
        repoManager.taRepo.insert(p_newInstructor->id(), p_newInstructor);
    }
    m_data.push_back(p_newInstructor);
    endInsertRows();
    qDebug() << "adding instructor: " + name + " " + email + " ";

}
