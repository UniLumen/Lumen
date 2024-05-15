#include "schedule.h"
#include <QDebug>
#include "scheduleoptimizer.h"
std::vector<std::vector<TimeSlot>*>Schedule::schedules;
std::vector<std::vector<std::vector<TimeSlot>>> Schedule::formatedSchedules;
std::vector<std::vector<std::vector<TimeSlot>>> Schedule::optimizedSchedules;
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
void Schedule::createOptimizedSchedule()
{
    auto minimizedTables = ScheduleOptimizer::minimizedTables; //vector of vector of timeslot
    for(int i = 0;i < minimizedTables.size(); i++)
    {
        for(int j = 0;j<6;j++)
        {
            std::vector<QString> currentDayPlaces;
            for(int k = 0; k < minimizedTables[i].size();i++)
            {
                if(minimizedTables[i][k].day == j)
                {
                    if(std::find(currentDayPlaces.begin(),currentDayPlaces.end(),minimizedTables[i][k].place) == currentDayPlaces.end())
                    {
                        //place is not in vector
                        currentDayPlaces.push_back(minimizedTables[i][k].place);
                        optimizedSchedules[i][j].push_back(TimeSlot(minimizedTables[i][j].place));
                    }
                }
            }
            currentDayPlaces.clear();
            optimizedSchedules[i][j].push_back(TimeSlot(""));
            optimizedSchedules[i][j].push_back(TimeSlot(""));
            optimizedSchedules[i][j].push_back(TimeSlot(""));
            optimizedSchedules[i][j].push_back(TimeSlot(""));
            optimizedSchedules[i][j].push_back(TimeSlot(""));
            optimizedSchedules[i][j].push_back(TimeSlot(""));
        }
    }

}
