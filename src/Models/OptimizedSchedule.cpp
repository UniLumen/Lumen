#include "OptimizedSchedule.h"
#include <unordered_map>

namespace Lumen {
    OptimizedSchedule::OptimizedSchedule(int selectedGroup, int selectedSection, std::unordered_map<QString, bool> attendingDays)
    : m_selectedGroup(selectedGroup), m_selectedSection(selectedSection), m_attendingDays(attendingDays) {};

    int OptimizedSchedule::getSelectedGroup(){
        return m_selectedGroup;
    }

    int OptimizedSchedule::getSelectedSection(){
        return m_selectedSection;
    }

    std::unordered_map<QString, bool> OptimizedSchedule::getAttendingDays(){
        return m_attendingDays;
    }

    int OptimizedSchedule::getNumberOfAttendingDays(){
        int numberOfAttendingDays = 0;

        for(auto dayAttendance : m_attendingDays){
            numberOfAttendingDays += dayAttendance.second;
        }

        return numberOfAttendingDays;
    }
}
