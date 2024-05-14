#include "schedule.h"
#include <QDebug>
std::vector<std::unordered_map<int, std::vector<TimeSlot>>> Schedule::schedules;
void Schedule::addSchedule(std::unordered_map<int, std::vector<TimeSlot>> newSchedule)
{
    Schedule::schedules.push_back(newSchedule);
    qDebug() <<"added";
}
