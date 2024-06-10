#include "timeslotmodel.h"
#include <QDebug>
#include "schedule.h"

TimeSlotModel::TimeSlotModel(QObject *parent){
    qDebug() << m_currentDay << ' ' << m_currentTable << '\n';
}
int TimeSlotModel::rowCount(const QModelIndex& parent) const{

    if (parent.isValid()){
        return 0;
    }
    // qDebug() << "rowCount:" << static_cast<int>(Schedule::dataSet[m_currentTable][m_currentDay].size());
    return static_cast<int>(Schedule::dataSet[m_currentTable][m_currentDay].size());
}


QVariant TimeSlotModel::data(const QModelIndex& index, int role) const{
    if(!index.isValid()){
        return QVariant();
    }
    qDebug() << "data index:" << index.row() << "role:" << role;
    const TimeSlot &timeSlot = Schedule::dataSet[m_currentTable][m_currentDay].at(index.row());
    switch (role){
        case Roles::Place: return timeSlot.place;
        case Roles::Day: return timeSlot.day;
        case Roles::PrimaryInstructor: return timeSlot.primaryInstructor;
        case Roles::SectionNumbers: return QVariant::fromValue(timeSlot.sectionNumbers);
        case Roles::TimePeriod: return static_cast<int>(timeSlot.timePeriod);
        case Roles::SecondaryInstructor: return timeSlot.secondaryInstructor;
        case Roles::Type: return timeSlot.type;
        case Roles::Course: return timeSlot.course;
        case Roles::DisplayText: return timeSlot.displayText;
        default: return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> TimeSlotModel::roleNames() const{
    QHash<int, QByteArray> mapping{
        {Roles::Place, "place"},
        {Roles::Day, "day"},
        {Roles::PrimaryInstructor, "primaryInstructor"},
        {Roles::SectionNumbers, "sectionNumbers"},
        {Roles::TimePeriod, "timePeriod"},
        {Roles::SecondaryInstructor, "secondaryInstructor"},
        {Roles::Type, "type"},
        {Roles::Course, "course"},
        {Roles::DisplayText,"displayText"}
    };
    return mapping;
}

void TimeSlotModel::editSelectedCell(int index,const int &day,const int &sectionNum,const QString &type
                                     ,const QString &primaryInstructor
                                     ,const QString &secondaryInstructor
                                     ,const QString &course
                                     ,const QString &displayText){
    qDebug() << m_currentDay << ' ' << m_currentTable << '\n';
    if ((index % 7) < 1){
        return;
    }

    auto& daySlots = Schedule::dataSet[m_currentTable][m_currentDay];
    beginResetModel();
    TimeSlot& timeSlot = daySlots[index];
    timeSlot.day = day;
    timeSlot.place = daySlots[index - (index % 7)].place;
    timeSlot.sectionNumbers = sectionNum;
    timeSlot.type = type;
    timeSlot.primaryInstructor = primaryInstructor;
    timeSlot.secondaryInstructor = secondaryInstructor;
    timeSlot.course = course;
    timeSlot.displayText = displayText;
    // Schedule::dataSet[m_currentDay][index].timePeriod = index;
    switch(index % 7)
    {
        case 1: timeSlot.timePeriod = 8;break;
        case 2: timeSlot.timePeriod = 10;break;
        case 3: timeSlot.timePeriod = 12;break;
        case 4: timeSlot.timePeriod = 2;break;
        case 5: timeSlot.timePeriod = 4;break;
        case 6: timeSlot.timePeriod = 6;break;
    }
    endResetModel();
}
void TimeSlotModel::onRemoveTimeSlot(int index){
    auto& daySlots = Schedule::dataSet[m_currentTable][m_currentDay];
    beginResetModel();
    daySlots[index] = TimeSlot("");
    endResetModel();
}
void TimeSlotModel::addRow(const QString &place){
    if(exist(place)){
        qDebug() << m_currentDay << ' ' << m_currentTable << '\n';
        qDebug() << "NO\n";
        return;
    }
    auto& daySlots = Schedule::dataSet[m_currentTable][m_currentDay];
    beginResetModel();
    for (int i = 0; i < 7; ++i) {
        daySlots.push_back(i == 0 ? TimeSlot(place) : TimeSlot(" "));
    }
    qDebug() << "ahaa";
    endResetModel();
    emit rowCountChanged();
}
void TimeSlotModel::removeRow()
{
    auto& daySlots = Schedule::dataSet[m_currentTable][m_currentDay];
    beginResetModel();
    daySlots.erase(daySlots.end() - 7, daySlots.end());
    endResetModel();
    emit rowCountChanged();
}

double TimeSlotModel::getRows() const
{
    return Schedule::dataSet[m_currentTable][m_currentDay].size() * 1.0;
}
void TimeSlotModel::setCurrentDay(const int &day)
{
    if(day < 1 && day > 5)
        return;
    m_currentDay = day;
    emit currentDayChanged();
}

int TimeSlotModel::getCurrentDay() const
{
    return m_currentDay;
}
void TimeSlotModel::setCurrentTable(const int &table)
{
    m_currentTable = table;
    emit currentTableChanged();
}

int TimeSlotModel::getCurrentTable() const
{
    return m_currentTable;
}
bool TimeSlotModel::exist(const QString &place) const {
    const auto& daySlots = Schedule::dataSet[m_currentTable][m_currentDay];
    for (int i = 0; i < daySlots.size(); i += 7) {
        if (daySlots[i].place == place) {
            return true;
        }
    }
    return false;
}
