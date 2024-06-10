#include "schedule.h"
#include <QDebug>
#include "scheduleoptimizer.h"

// Define the static members
std::vector<std::vector<TimeSlot>*> Schedule::schedules;
std::vector<std::vector<std::vector<TimeSlot>>> Schedule::formatedSchedules;
std::vector<std::vector<std::vector<TimeSlot>>> Schedule::optimizedSchedules;
std::unordered_map<int, std::unordered_map<int, std::vector<TimeSlot>>> Schedule::dataSet; // corrected definition
std::unordered_map<int, std::unordered_map<int, std::vector<TimeSlot>>> Schedule::test; // define this too if it's used

void Schedule::addSchedule(std::vector<TimeSlot> *newSchedule)
{
    Schedule::schedules.push_back(newSchedule);
    qDebug() << "added";
}

void Schedule::FormatSchedule()
{
    for(int i = 0; i < 4; i++)
    {
        std::vector<std::vector<TimeSlot>> newTable;
        for(int j = 5; j >= 0; j--)
        {
            newTable.push_back(*Schedule::schedules[Schedule::schedules.size()-1 - j]);
        }
        for(int k = 0; k < 6; k++)
        {
            Schedule::schedules.pop_back();
        }
        Schedule::formatedSchedules.push_back(newTable);
    }
}

void Schedule::createOptimizedSchedule()
{
    auto minimizedTables = ScheduleOptimizer::minimizedTables; // vector of vector of timeslot
    for(int i = 0; i < minimizedTables.size(); i++)
    {
        for(int j = 0; j < 6; j++)
        {
            std::vector<QString> currentDayPlaces;
            for(int k = 0; k < minimizedTables[i].size(); k++) // changed from i to k in the loop condition
            {
                if(minimizedTables[i][k].day == j)
                {
                    if(std::find(currentDayPlaces.begin(), currentDayPlaces.end(), minimizedTables[i][k].place) == currentDayPlaces.end())
                    {
                        // place is not in vector
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
