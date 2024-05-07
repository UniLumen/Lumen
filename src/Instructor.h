#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <QString>

class Instructor{
public:
    Instructor(QString name, QString email):
        name(name), email(email){
    }
    QString name;
    QString email;
};

#endif // INSTRUCTOR_H
