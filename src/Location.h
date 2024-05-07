#ifndef LOCATION_H
#define LOCATION_H

#include<QString>

class Location
{
public:
    Location(QString name, QString building, int floor, QString description):
        name(name), building(building), floor(floor), description(description){
    }

    QString name;
    QString building;
    QString description;
    int floor;
};

#endif // LOCATION_H
