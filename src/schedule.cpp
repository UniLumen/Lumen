#include "schedule.h"
#include <QDebug>
std::vector<std::vector<TimeSlot>*>Schedule::schedules;
std::vector<std::vector<std::vector<TimeSlot>>> Schedule::formatedSchedules;
void Schedule::addSchedule(std::vector<TimeSlot>  *newSchedule)
{
    Schedule::schedules.push_back(newSchedule);
    qDebug() <<"added";
}
void Schedule::FormatSchedule()
{
    for(int i = 0; i < 4; i++)
    {
        std::vector<std::vector<TimeSlot>> newTable;
        for(int i = 5; i >= 0; i--)
        {
            newTable.push_back(*Schedule::schedules[Schedule::schedules.size()-1 - i]);
        }
        for(int i = 0; i < 6;i++)
        {
            Schedule::schedules.pop_back();
        }
        Schedule::formatedSchedules.push_back(newTable);
    }
}
