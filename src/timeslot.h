#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <QString>
#include <list>

class TimeSlot
{
public:

    TimeSlot(const QString &displayText):
        displayText(displayText){};
    TimeSlot(const int &day, const QString &place,const short int &timePeriod, const short int &sectionNumbers, const QString &type, const QString &primaryInstructor, const QString &secondaryInstructor,const QString course):
        day(day), place(place), timePeriod(timePeriod), sectionNumbers(sectionNumbers), type(type), primaryInstructor(primaryInstructor), secondaryInstructor(secondaryInstructor),course(course){};

    int day;
    QString place;
    short int timePeriod;
    short int sectionNumbers;
    QString type;
    QString primaryInstructor;
    QString secondaryInstructor;
    QString course;
    QString displayText;
};

#endif // TIMESLOT_H
