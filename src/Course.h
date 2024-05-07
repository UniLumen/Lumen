#ifndef COURSE_H
#define COURSE_H

#include <QString>

class Course
{
public:
    Course(QString name, int creditHours, int yearOfStudy, QString dept, bool hasLab, bool hasTutorial):
        name(name), creditHours(creditHours), yearOfStudy(yearOfStudy), dept(dept), hasLab(hasLab), hasTutorial(hasTutorial){
    }
    QString name;
    int creditHours;
    int yearOfStudy;
    QString dept;
    bool hasLab;
    bool hasTutorial;
};

#endif // COURSE_H
