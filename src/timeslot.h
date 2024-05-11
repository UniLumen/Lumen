#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <QString>

class TimeSlot {
public:
    TimeSlot();
    TimeSlot(QString day, QString place, QString timePeriods, short int sectionNum, short int groupNum, QString type);

    // Getter methods for all attributes
    QString getDay();
    QString getPlace();
    QStringList getTimePeriods(); // Returns a list of time periods
    short int getSectionNum();
    short int getGroupNum();
    QString getType();
    QString getPrimaryInstructor();
    QString getSecondaryInstructor();

private:
    QString day;
    QString place;
    QString timePeriods; // List of strings representing time periods (e.g., "10:00-12:00", "13:00-14:00")
    short int sectionNum;
    short int groupNum;
    QString type;
    QString primaryInstructor;
    QString secondaryInstructor;
};

#endif // TIMESLOT_H
