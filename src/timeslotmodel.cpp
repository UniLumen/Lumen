#include "timeslotmodel.h"
#include <QDebug>
// #include "QAbstractListModel"

// void TimeSlotModel::setData(const int &day)
// {

// }

void TimeSlotModel::setDay(const int &day)
{
    if(day < 0 && day > 6)
        return;
    currentDay = day;
    emit dayChanged();
}

int TimeSlotModel::getDay()
{
    return currentDay;
}

TimeSlotModel::TimeSlotModel(QObject *parent):
    QAbstractListModel(parent){
    TimeSlot a("Cislaaa");
    timeSlot_data.push_back(a),
    timeSlot_data.push_back(TimeSlot("CIS 2")),
    timeSlot_data.push_back(TimeSlot("CIS 3")),
    timeSlot_data.push_back(TimeSlot("CIS 4")),
    timeSlot_data.push_back(TimeSlot("CIS 5")),
    timeSlot_data.push_back(TimeSlot("CIS 6"));
    timeSlot_data.push_back(TimeSlot("CIS 6"));
    timeSlot_data.push_back(TimeSlot("CIS lab1")),
    timeSlot_data.push_back(TimeSlot("CIS 2")),
    timeSlot_data.push_back(TimeSlot("CIS 3")),
    timeSlot_data.push_back(TimeSlot("CIS 4")),
    timeSlot_data.push_back(TimeSlot("CIS 5")),
    timeSlot_data.push_back(TimeSlot("CIS 6"));
    timeSlot_data.push_back(TimeSlot("CIS 6"));
    timeSlot_data.push_back(TimeSlot("CIS lab1")),
    timeSlot_data.push_back(TimeSlot("CIS 2")),
    timeSlot_data.push_back(TimeSlot("CIS 3")),
    timeSlot_data.push_back(TimeSlot("CIS 4")),
    timeSlot_data.push_back(TimeSlot("a7aaa")),
    timeSlot_data.push_back(TimeSlot("CIS 6"));
    timeSlot_data.push_back(TimeSlot("CIS 6"));
    timeSlot_data_sun.push_back(TimeSlot("a7aaa"));
    timeSlot_data_sun.push_back(TimeSlot("a7aaa"));
    timeSlot_data_sun.push_back(TimeSlot("a7aaa"));
    timeSlot_data_sun.push_back(TimeSlot("a7aaa"));
    timeSlot_data_sun.push_back(TimeSlot("a7aaa"));
    timeSlot_data_sun.push_back(TimeSlot("a7aaa"));
    timeSlot_data_sun.push_back(TimeSlot("a7aaa"));
}

int TimeSlotModel::rowCount(const QModelIndex& parent) const{

    if (parent.isValid()){
        return 0;
    }
    if(currentDay == 0)
        return timeSlot_data.size();
    else
        return timeSlot_data_sun.size();
}


QVariant TimeSlotModel::data(const QModelIndex& index, int role) const{
    if(!index.isValid()){
        return QVariant();
    }
    // int RowCount = 14;
    if(currentDay == 0){
        const TimeSlot &timeSlot = timeSlot_data.at(index.row());
        switch (role) {
            case Roles::Place: return timeSlot.place;
            case Roles::Day: return timeSlot.day;
            case Roles::PrimaryInstructor: return timeSlot.primaryInstructor;
            case Roles::SectionNumbers: return QVariant::fromValue(timeSlot.sectionNumbers);
            // case Roles::timePeriod: return static_cast<int>(data.timePeriod);
            case Roles::SecondaryInstructor: return timeSlot.secondaryInstructor;
            case Roles::Type: return timeSlot.type;
            default: return QVariant();
        }
    }
    else{
        const TimeSlot &timeSlot = timeSlot_data_sun.at(index.row());
        switch (role) {
            case Roles::Place: return timeSlot.place;
            case Roles::Day: return timeSlot.day;
            case Roles::PrimaryInstructor: return timeSlot.primaryInstructor;
            case Roles::SectionNumbers: return QVariant::fromValue(timeSlot.sectionNumbers);
            // case Roles::timePeriod: return static_cast<int>(data.timePeriod);
            case Roles::SecondaryInstructor: return timeSlot.secondaryInstructor;
            case Roles::Type: return timeSlot.type;
            default: return QVariant();
        }
    }
    return QVariant();
}

QHash<int, QByteArray> TimeSlotModel::roleNames() const{
    QHash<int, QByteArray> mapping{
        {Roles::Place, "place"},
        {Roles::Day, "day"},
        {Roles::PrimaryInstructor, "primaryInstructor"},
        {Roles::SectionNumbers, "sectionNumbers"},
        {Roles::timePeriod, "timePeriod"},
        {Roles::SecondaryInstructor, "secondaryInstructor"},
        {Roles::Type, "type"}
    };
    return mapping;
}
void TimeSlotModel::editSelectedCell(int index, QString lmao){
    if (index < 0 && index >= timeSlot_data.size()){
        return;
    }
    if(currentDay == 0){
        beginResetModel();
        timeSlot_data[index].place = lmao;
        endResetModel();
    }
    else{
        beginResetModel();
        timeSlot_data_sun[index].place = "lmao";
        endResetModel();
    }
}

void TimeSlotModel::addRow(){
    beginResetModel();
    if(currentDay == 0){
    timeSlot_data.push_back(TimeSlot("CIS lab1")),
    timeSlot_data.push_back(TimeSlot("CIS 2")),
    timeSlot_data.push_back(TimeSlot("CIS 3")),
    timeSlot_data.push_back(TimeSlot("CIS 4")),
    timeSlot_data.push_back(TimeSlot("a7aaa")),
    timeSlot_data.push_back(TimeSlot("CIS 6"));
    timeSlot_data.push_back(TimeSlot("CIS 6"));
    }else{
        timeSlot_data_sun.push_back(TimeSlot("CIS lab1")),
        timeSlot_data_sun.push_back(TimeSlot("CIS 2")),
        timeSlot_data_sun.push_back(TimeSlot("CIS 3")),
        timeSlot_data_sun.push_back(TimeSlot("CIS 4")),
        timeSlot_data_sun.push_back(TimeSlot("a7aaa")),
        timeSlot_data_sun.push_back(TimeSlot("CIS 6"));
        timeSlot_data_sun.push_back(TimeSlot("CIS 6"));
    }
    qDebug() << "ahaa";
    endResetModel();
    emit rowCountChanged();
}

double TimeSlotModel::getRows() const
{
    if(currentDay == 0)
        return timeSlot_data.size() * 1.0;
    else
        return timeSlot_data_sun.size() * 1.0;
}
