#include "timeslotmodel.h"
#include <QDebug>
// #include "QAbstractListModel"
#include "schedule.h"
std::unordered_map<int, std::vector<TimeSlot>> TimeSlotModel::dataSet;

TimeSlotModel::TimeSlotModel(QObject *parent){
    Schedule::addSchedule(&dayGrid);
    dayGrid.push_back(TimeSlot("CIS 2"));
    dayGrid.push_back(TimeSlot(""));
    dayGrid.push_back(TimeSlot(""));
    dayGrid.push_back(TimeSlot(""));
    dayGrid.push_back(TimeSlot(""));
    dayGrid.push_back(TimeSlot(""));
    dayGrid.push_back(TimeSlot(""));

    // m_currentDay = -1;
}
int TimeSlotModel::rowCount(const QModelIndex& parent) const{

    if (parent.isValid()){
        return 0;
    }
    return (int)dayGrid.size();
}


QVariant TimeSlotModel::data(const QModelIndex& index, int role) const{
    if(!index.isValid()){
        return QVariant();
    }
    const TimeSlot &timeSlot = dayGrid.at(index.row());
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

// Qt::ItemFlags timeslotmodel::flags(const QModelIndex &index) const override {
//     Qt::ItemFlags flags = QAbstractListModel::flags(index);
//     flags << Qt::ItemIsPersistent;  // Add this flag
//     return flags;
// }

void TimeSlotModel::editSelectedCell(int index,const int &day,const int &sectionNum,const QString &type
                                     ,const QString &primaryInstructor
                                     ,const QString &secondaryInstructor
                                     ,const QString &course
                                     ,const QString &displayText){
    if ((index % 7) < 1){
        return;
    }
    beginResetModel();
    dayGrid[index].day = day;
    dayGrid[index].place = dayGrid[index - (index % 7)].place;
    dayGrid[index].sectionNumbers = sectionNum;
    dayGrid[index].type = type;
    dayGrid[index].primaryInstructor = primaryInstructor;
    dayGrid[index].secondaryInstructor = secondaryInstructor;
    dayGrid[index].course = course;
    dayGrid[index].displayText = displayText;
    switch(index % 7)
    {
    case 1: dayGrid[index].timePeriod = 8;break;
    case 2: dayGrid[index].timePeriod = 10;break;
    case 3: dayGrid[index].timePeriod = 12;break;
    case 4: dayGrid[index].timePeriod = 2;break;
    case 5: dayGrid[index].timePeriod = 4;break;
    case 6: dayGrid[index].timePeriod = 6;break;
    }
    endResetModel();
    //TimeSlotModel::dataSet[m_currentDay].push_back(dayGrid[m_currentDay][index]);
    TimeSlot ti = dayGrid[index];
    //qDebug() << ti.timePeriod << ' ' << ti.course << ' ' << ti.day << ' ' << ti.place;
    //qDebug() << m_currentDay << "\n";
}
void TimeSlotModel::onRemoveTimeSlot(int index){
    beginResetModel();
    //TimeSlotModel::dataSet[m_currentDay].erase(dayGrid[m_currentDay][index]);
    dayGrid.erase(dayGrid.begin()+index);
    dayGrid.insert(dayGrid.begin()+index,TimeSlot(""));
    qDebug() << "onRemove timeSlot called on index: " + std::to_string(index);
    endResetModel();
}
void TimeSlotModel::addRow(const QString &place){
    beginResetModel();
    dayGrid.push_back(TimeSlot(place));
    dayGrid.push_back(TimeSlot(" "));
    dayGrid.push_back(TimeSlot(" "));
    dayGrid.push_back(TimeSlot(" "));
    dayGrid.push_back(TimeSlot(" "));
    dayGrid.push_back(TimeSlot(" "));
    dayGrid.push_back(TimeSlot(" "));
    qDebug() << "ahaa";
    endResetModel();
    emit rowCountChanged();
}
void TimeSlotModel::addToSchedule()
{
    Schedule::schedules.push_back(&dayGrid);
}
void TimeSlotModel::removeRow()
{
    beginResetModel();
    dayGrid.erase(dayGrid.end() - 7, dayGrid.end());
    endResetModel();
    emit rowCountChanged();
}

double TimeSlotModel::getRows() const
{
    return dayGrid.size() * 1.0;
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
    emit currentDayChanged();
}

int TimeSlotModel::getCurrentTable() const
{
    return m_currentTable;
}
void TimeSlotModel::setGridDays()
{
    dayGrid = Schedule::formatedSchedules[m_currentTable][m_currentDay];
}
