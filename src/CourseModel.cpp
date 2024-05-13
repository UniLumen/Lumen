#include <QDebug>
#include "CourseModel.h"
using namespace Lumen;

CourseModel::CourseModel(QObject *parent):
    QAbstractListModel(parent){
    m_data = repoManager.courseRepo.getAll();
}

int CourseModel::rowCount(const QModelIndex &parent) const{
    if(parent.isValid()){
        return 0;
    }

    return m_data.size();
}

QVariant CourseModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()){
        return QVariant();
    }

    const Course* data= m_data.at(index.row());

    switch(role){
        case Roles::Name: return data->name();
        case Roles::CreditHours: return data->creditHours();
        case Roles::YearOfStudy: return data->yearOfStudy();
        case Roles::Department: return data->department();
        default: return QVariant();
    }
}

QHash<int, QByteArray> CourseModel::roleNames() const{
    QHash<int, QByteArray> mapping{
        {Roles::Name, "name"},
        {Roles::CreditHours, "creditHours"},
        {Roles::YearOfStudy, "YearOfStudy"},
        {Roles::Department, "dept"}
    };

    return mapping;
}

void CourseModel::onRemoveCourse(int index){
    beginRemoveRows(QModelIndex(), index,index);
    repoManager.courseRepo.remove(m_data[index]->id());
    m_data.erase(m_data.begin()+index);
    qDebug() << "onRemove course called on index: " + std::to_string(index);
    endRemoveRows();
}

void CourseModel::onAddCourse(QString name, QString year, QString dept, QString credits, bool hasLab, bool hasTutorial){
    beginInsertRows(QModelIndex(),m_data.size(), m_data.size());
    unsigned int courseCompontents = 1; //001
    if(hasLab){
        courseCompontents = courseCompontents & 2; //010
    }
    if(hasTutorial){
        courseCompontents = courseCompontents & 4; //100
    }
    Course* p_newCourse = new Course(name, year.toInt(), dept, credits.toInt(), courseCompontents);
    m_data.push_back(p_newCourse);
    repoManager.courseRepo.insert(p_newCourse->id(), p_newCourse);
    endInsertRows();
    qDebug() << "adding subject: " + name + " " + year + " " + dept + " " + credits + " hasLab: "  + QString::number(hasLab) + "hasTutorial: " + QString::number(hasTutorial);

}




