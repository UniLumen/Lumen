#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <QVector>
#include "timeslot.h"
class Schedule
{
public:
    Schedule();
    static std::vector<std::unordered_map<int, std::vector<TimeSlot>>> schedules;
    static void addSchedule(std::unordered_map<int, std::vector<TimeSlot>> newSchedule);
};

#endif // SCHEDULE_H
