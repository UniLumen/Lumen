#pragma once

#include <QtCore>

namespace Lumen {

    class OptimizedSchedule {
    public:
        OptimizedSchedule(int selectedGroup, int selectedSection, QHash<QString, bool> attendingDays);
        int getSelectedGroup();
        int getSelectedSection();
        QHash<QString, bool> getAttendingDays();
    private:
        int m_selectedGroup;
        int m_selectedSection;
        QHash<QString, bool> m_attendingDays;
        // Should later store here the optimized schedule itself
    };

}
