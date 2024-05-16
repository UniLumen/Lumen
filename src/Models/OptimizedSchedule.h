#pragma once

#include <unordered_map>
#include <QtCore>

namespace Lumen {

    class OptimizedSchedule {
    public:
        OptimizedSchedule(int selectedGroup, int selectedSection, std::unordered_map<QString, bool> attendingDays);
        int getSelectedGroup();
        int getSelectedSection();
        std::unordered_map<QString, bool> getAttendingDays();
        int getNumberOfAttendingDays();
    private:
        int m_selectedGroup;
        int m_selectedSection;
        std::unordered_map<QString, bool> m_attendingDays;
        // Should later store here the optimized schedule itself
    };

}
