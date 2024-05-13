#include "timeslotmodel.h"
#include <QDebug>
// #include "QAbstractListModel"


TimeSlotModel::TimeSlotModel(QObject *parent):
    QAbstractListModel(parent){
    dayGrid[0].push_back(TimeSlot("CIS 2"));
    dayGrid[0].push_back(TimeSlot(""));
    dayGrid[0].push_back(TimeSlot(""));
    dayGrid[0].push_back(TimeSlot(""));
    dayGrid[0].push_back(TimeSlot(""));
    dayGrid[0].push_back(TimeSlot(""));
    dayGrid[0].push_back(TimeSlot(""));
    dayGrid[1].push_back(TimeSlot("CIS 3"));
    dayGrid[1].push_back(TimeSlot(""));
    dayGrid[1].push_back(TimeSlot(""));
    dayGrid[1].push_back(TimeSlot(""));
    dayGrid[1].push_back(TimeSlot(""));
    dayGrid[1].push_back(TimeSlot(""));
    dayGrid[1].push_back(TimeSlot(""));
    dayGrid[2].push_back(TimeSlot("CIS 4"));
    dayGrid[2].push_back(TimeSlot(""));
    dayGrid[2].push_back(TimeSlot(""));
    dayGrid[2].push_back(TimeSlot(""));
    dayGrid[2].push_back(TimeSlot(""));
    dayGrid[2].push_back(TimeSlot(""));
    dayGrid[2].push_back(TimeSlot(""));
    dayGrid[3].push_back(TimeSlot("CIS 5"));
    dayGrid[3].push_back(TimeSlot(""));
    dayGrid[3].push_back(TimeSlot(""));
    dayGrid[3].push_back(TimeSlot(""));
    dayGrid[3].push_back(TimeSlot(""));
    dayGrid[3].push_back(TimeSlot(""));
    dayGrid[3].push_back(TimeSlot(""));
    dayGrid[4].push_back(TimeSlot("CIS 7"));
    dayGrid[4].push_back(TimeSlot(""));
    dayGrid[4].push_back(TimeSlot(""));
    dayGrid[4].push_back(TimeSlot(""));
    dayGrid[4].push_back(TimeSlot(""));
    dayGrid[4].push_back(TimeSlot(""));
    dayGrid[4].push_back(TimeSlot(""));
    dayGrid[5].push_back(TimeSlot("CIS 8"));
    dayGrid[5].push_back(TimeSlot(""));
    dayGrid[5].push_back(TimeSlot(""));
    dayGrid[5].push_back(TimeSlot(""));
    dayGrid[5].push_back(TimeSlot(""));
    dayGrid[5].push_back(TimeSlot(""));
    dayGrid[5].push_back(TimeSlot(""));
    dayGrid[6].push_back(TimeSlot("CIS 9"));
    dayGrid[6].push_back(TimeSlot(""));
    dayGrid[6].push_back(TimeSlot(""));
    dayGrid[6].push_back(TimeSlot(""));
    dayGrid[6].push_back(TimeSlot(""));
    dayGrid[6].push_back(TimeSlot(""));
    dayGrid[6].push_back(TimeSlot(""));
    // m_currentDay = -1;
}

int TimeSlotModel::rowCount(const QModelIndex& parent) const{

    if (parent.isValid()){
        return 0;
    }
    return (int)dayGrid.at(m_currentDay).size();
}


QVariant TimeSlotModel::data(const QModelIndex& index, int role) const{
    if(!index.isValid()){
        return QVariant();
    }
    const TimeSlot &timeSlot = dayGrid.at(m_currentDay).at(index.row());
    switch (role){
        case Roles::Place: return timeSlot.place;
        case Roles::Day: return timeSlot.day;
        case Roles::PrimaryInstructor: return timeSlot.primaryInstructor;
        case Roles::SectionNumbers: return QVariant::fromValue(timeSlot.sectionNumbers);
        case Roles::TimePeriod: return static_cast<int>(timeSlot.timePeriod);
        case Roles::SecondaryInstructor: return timeSlot.secondaryInstructor;
        case Roles::Type: return timeSlot.type;
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
        {Roles::Type, "type"}
    };
    return mapping;
}

// Qt::ItemFlags timeslotmodel::flags(const QModelIndex &index) const override {
//     Qt::ItemFlags flags = QAbstractListModel::flags(index);
//     flags << Qt::ItemIsPersistent;  // Add this flag
//     return flags;
// }

void TimeSlotModel::editSelectedCell(int index, QString lmao){
    if ((index % 7) < 1){
        return;
    }
    beginResetModel();
    dayGrid.at(m_currentDay).at(index).place = lmao;
    endResetModel();
}

void TimeSlotModel::addRow(const QString &place){
    beginResetModel();
    dayGrid.at(m_currentDay).push_back(TimeSlot(place));
    dayGrid.at(m_currentDay).push_back(TimeSlot(" "));
    dayGrid.at(m_currentDay).push_back(TimeSlot(" "));
    dayGrid.at(m_currentDay).push_back(TimeSlot(" "));
    dayGrid.at(m_currentDay).push_back(TimeSlot(" "));
    dayGrid.at(m_currentDay).push_back(TimeSlot(" "));
    dayGrid.at(m_currentDay).push_back(TimeSlot(" "));
    qDebug() << "ahaa";
    endResetModel();
    emit rowCountChanged();
}

void TimeSlotModel::removeRow()
{
    beginResetModel();
    dayGrid[m_currentDay].erase(dayGrid[m_currentDay].end() - 7, dayGrid[m_currentDay].end());
    endResetModel();
    emit rowCountChanged();
}

double TimeSlotModel::getRows() const
{
    return dayGrid.at(m_currentDay).size() * 1.0;
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
