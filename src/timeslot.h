#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <QString>

class TimeSlot
{
public:
    TimeSlot();
    QString day;
    int hour;
    QString place;
    short int sectionNum;
    short int groupNum;
    QString type[3] = {"Lecture","Tutorial","Lab"};
    //course to be added
};

#endif // TIMESLOT_H
