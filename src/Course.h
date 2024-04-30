#ifndef COURSE_H
#define COURSE_H

#include <QString>

class Course
{
public:
    Course(QString name, int creditHours, int yearOfStudy, QString dept):
        name(name), creditHours(creditHours), yearOfStudy(yearOfStudy), dept(dept){
    }
    QString name;
    int creditHours;
    int yearOfStudy;
    QString dept;
};

#endif // COURSE_H
