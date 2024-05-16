#include "OptimizedScheduleView.h"
#include "Models/OptimizedSchedule.h"

#include <QDebug>
#include <unordered_map>

OptimizedScheduleView::OptimizedScheduleView(QObject* parent) : QAbstractListModel(parent) {}

int OptimizedScheduleView::rowCount(const QModelIndex& parent) const {
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) {
        return 0;
    }

    return m_optimizedSchedules.count();
}

QHash<int, QByteArray> OptimizedScheduleView::roleNames() const {
    static QHash<int, QByteArray> mapping {
        {        SelectedGroupRole,        "selectedGroup"},
        {      SelectedSectionRole,      "selectedSection"},
        {   SaturdayAttendanceRole,   "saturdayAttendance"},
        {     SundayAttendanceRole,     "sundayAttendance"},
        {     MondayAttendanceRole,     "mondayAttendance"},
        {    TuesdayAttendanceRole,    "tuesdayAttendance"},
        {  WednesdayAttendanceRole,  "wednesdayAttendance"},
        {   ThursdayAttendanceRole,   "thursdayAttendance"},
        { NumberOfDaysToAttendRole, "numberOfDaysToAttend"},
    };

    return mapping;
}

QVariant OptimizedScheduleView::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= m_optimizedSchedules.size() || index.row() < 0) {
        return QVariant();
    }

    OptimizedSchedule optimizedSchedule = m_optimizedSchedules.at(index.row());
    std::unordered_map<QString, bool> attendingDays = optimizedSchedule.getAttendingDays();
    switch (role) {
        case SelectedGroupRole:
            return optimizedSchedule.getSelectedGroup();
        case SelectedSectionRole:
            return optimizedSchedule.getSelectedSection();
        case SaturdayAttendanceRole:
            return attendingDays["Saturday"];
        case SundayAttendanceRole:
            return attendingDays["Sunday"];
        case MondayAttendanceRole:
            return attendingDays["Monday"];
        case TuesdayAttendanceRole:
            return attendingDays["Tuesday"];
        case WednesdayAttendanceRole:
            return attendingDays["Wednesday"];
        case ThursdayAttendanceRole:
            return attendingDays["Thursday"];
        case NumberOfDaysToAttendRole:
            return optimizedSchedule.getNumberOfAttendingDays();
        default:
            return QVariant();
    }

    return QVariant();
}

void OptimizedScheduleView::createOptimizedSchedules(int selectedGroup, int selectedSection){
    // Here should call the algorithm for optimizing schedule and give it the above 2 arguments
    // And get form it a vector containing all the optimized schedules
    // And then I should create a number of optimized schedule objects equal to the amount returned
    // And then assign to each object the above selectedGroup/Section + Generate the attendingDays map from the returned schedule
    // And assign the optimized schedule itself to the optimizedSchedule object
    // For now this is just a demo

    if (selectedGroup < 1 || selectedGroup > 30){
        m_inputValidationNote = "Please enter a valid group number between 1-30";
        emit postValidation();
        return;
    }
    else if(selectedSection < 1 || selectedSection > 30){
        m_inputValidationNote = "Please enter a valid section number between 1-30";
        emit postValidation();
        return;
    }
    else{
        m_inputValidationNote = "";
        emit postValidation();
    }

    m_numberOfOptimizedSchedulesAdded.push(1);

    std::unordered_map<QString, bool> attendingDays;

    if(selectedGroup == 2){
        attendingDays = {{"Saturday", 1}, {"Sunday", 1}, {"Monday", 0}, {"Tuesday", 0}, {"Wednesday", 0}, {"Thursday", 0}};
    }
    else if(selectedGroup == 4){
        attendingDays = {{"Saturday", 0}, {"Sunday", 1}, {"Monday", 1}, {"Tuesday", 1}, {"Wednesday", 1}, {"Thursday", 0}};
    }
    else{
        attendingDays = {{"Saturday", 1}, {"Sunday", 1}, {"Monday", 1}, {"Tuesday", 1}, {"Wednesday", 1}, {"Thursday", 1}};
    }

    OptimizedSchedule optimizedSchedule = OptimizedSchedule(selectedGroup, selectedSection, attendingDays);

    addOptimizedSchedule(optimizedSchedule);
}

void OptimizedScheduleView::addOptimizedSchedule(OptimizedSchedule optimizedSchedule){
    int index = m_optimizedSchedules.count();

    beginInsertRows(QModelIndex(), index, index);
    m_optimizedSchedules.push_back(optimizedSchedule);
    endInsertRows();
}

void OptimizedScheduleView::removeOptimizedSchedule(int index) {
    if (index < 0 || index >= m_optimizedSchedules.count()) {
        return;
    }

    OptimizedSchedule optimizedSchedule = m_optimizedSchedules.at(index);

    beginRemoveRows(QModelIndex(), index, index);
    m_optimizedSchedules.removeAt(index);
    endRemoveRows();

    while(!m_numberOfOptimizedSchedulesAdded.empty()){
        m_numberOfOptimizedSchedulesAdded.pop();
    }
}

void OptimizedScheduleView::undoAddedOptimizedSchedules(){
    if(m_numberOfOptimizedSchedulesAdded.empty()){
        return;
    }

    beginRemoveRows(QModelIndex(), m_optimizedSchedules.count() - m_numberOfOptimizedSchedulesAdded.top(), m_optimizedSchedules.count());
    m_optimizedSchedules.erase(m_optimizedSchedules.end() - m_numberOfOptimizedSchedulesAdded.top(), m_optimizedSchedules.end());
    endRemoveRows();

    m_numberOfOptimizedSchedulesAdded.pop();
}
