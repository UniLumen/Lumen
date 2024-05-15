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
    static std::vector<std::vector<std::vector<TimeSlot>>> optimizedSchedules;
    static void addSchedule(std::vector<TimeSlot> *newSchedule);
    static void FormatSchedule();
    static void createOptimizedSchedule();
};

#endif // SCHEDULE_H
