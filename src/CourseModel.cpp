#include "CourseModel.h"

CourseModel::CourseModel(QObject *parent):
    QAbstractListModel(parent){
    //TO DO: should have constructor load data from JSON file
    //for now I will add dummy data to the vector

    Course c1("ds", 3, 2,"general");
    Course c2("algo", 3, 2,"general");
    Course c3("OOP", 3, 2,"general");
    Course c4("suiii", 3, 2,"general");
    Course c5("suiii2", 3, 2,"general");


    m_data.push_back(c1);
    m_data.push_back(c2);
    m_data.push_back(c3);
    m_data.push_back(c4);
    m_data.push_back(c4);
    m_data.push_back(c5);

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

    const Course &data = m_data.at(index.row());

    switch(role){
        case Roles::Name: return data.name;
        case Roles::CreditHours: return data.creditHours;
        case Roles::YearOfStudy: return data.yearOfStudy;
        case Roles::Department: return data.dept;
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




