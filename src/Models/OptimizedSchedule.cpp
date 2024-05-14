#include "OptimizedSchedule.h"

namespace Lumen {
    OptimizedSchedule::OptimizedSchedule(int selectedGroup, int selectedSection, QHash<QString, bool> attendingDays)
    : m_selectedGroup(selectedGroup), m_selectedSection(selectedSection), m_attendingDays(attendingDays) {};

    int OptimizedSchedule::getSelectedGroup(){
        return m_selectedGroup;
    }

    int OptimizedSchedule::getSelectedSection(){
        return m_selectedSection;
    }

    QHash<QString, bool> OptimizedSchedule::getAttendingDays(){
        return m_attendingDays;
    }
}
