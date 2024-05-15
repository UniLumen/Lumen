#ifndef TIMESLOT_H
#define TIMESLOT_H
#include <QString>

class TimeSlot
{
public:

    TimeSlot(const QString &displayText):
        displayText(displayText),place(displayText){};
    TimeSlot(const int &day, const QString &place,const short int &timePeriod,
             const short int &sectionNumbers, const QString &type, const QString &primaryInstructor,
             const QString &secondaryInstructor,const QString course):
        day(day), place(place), timePeriod(timePeriod), sectionNumbers(sectionNumbers),
        type(type), primaryInstructor(primaryInstructor), secondaryInstructor(secondaryInstructor),
        course(course){};

    QString place;
    QString primaryInstructor;
    QString secondaryInstructor;
    QString type;
    QString course;
    QString displayText;
    int day;
    short int sectionNumbers;
    short int timePeriod;
};

#endif // TIMESLOT_H
