#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <QVector>
#include "timeslot.h"
class Schedule
{
public:
    Schedule();
    static std::vector<std::vector<TimeSlot>*> schedules;
    static std::vector<std::vector<std::vector<TimeSlot>>> formatedSchedules;
    static void addSchedule(std::vector<TimeSlot> *newSchedule);
    static void FormatSchedule();
};

#endif // SCHEDULE_H
