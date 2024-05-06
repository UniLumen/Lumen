#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <QVector>
#include "timeslot.h"
class Schedule
{
public:
    Schedule();
    QVector<TimeSlot> timeSlots;
};

#endif // SCHEDULE_H
