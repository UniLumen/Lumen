#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <QString>
#include <list>

class TimeSlot
{
public:
    enum class TimePeriod {
        Period_8_10,
        Period_10_12,
        Period_12_2,
        Period_2_4,
        Period_4_6,
        Period_6_8
    };

    TimeSlot(const QString &place):
        place(place){};
    TimeSlot(const QString &day, const QString &place, int &timePeriod, const std::list<int> &sectionNumbers, const QString &type, const QString &primaryInstructor, const QString &secondaryInstructor):
        day(day), place(place), timePeriod(static_cast<TimePeriod>(timePeriod)), sectionNumbers(sectionNumbers), type(type), primaryInstructor(primaryInstructor), secondaryInstructor(secondaryInstructor){};

    QString day;
    QString place;
    //course
    TimePeriod timePeriod;
    std::list<int> sectionNumbers;
    QString type;
    QString primaryInstructor;
    QString secondaryInstructor;
};

#endif // TIMESLOT_H
