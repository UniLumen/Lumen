#ifndef SCHEDULEOPTIMIZER_H
#define SCHEDULEOPTIMIZER_H
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <QDebug>
#include <QObject>
#include <QAbstractListModel>
#include <QString>
#include <QVector>
#include<QPair>
#include <QList>
#include<QMap>
#include <QtGlobal>
#include "timeslot.h"
#include "UserConf.h"

class ScheduleOptimizer
{
public:
    ScheduleOptimizer();
    static int getMinimumDays(int day, int time,int  mask,bool take,std::vector<std::vector<std::vector<TimeSlot>>>timeGrid);
    static std::vector<std::vector<TimeSlot>> getOptimizedSchedules(int section,std::vector<std::vector<std::vector<TimeSlot>>>timeGrid,Lumen::UserConf *userConf);
    static void buildOptimizedSchedules(int day, int time,int mask,bool take,std::vector<std::vector<std::vector<TimeSlot>>>timeGrid);
    static int MASK;
    static int initialMask;
    static std::map<std::pair<int,int>,int> requredAttendanceTimeSlots;
    static std::vector<TimeSlot>mandatoryTimeSlots;
    static std::vector<std::vector<TimeSlot>>minimizedTables;
    static std::vector<TimeSlot>minimizedTable;
    static int dp[7][7][1<<15][2];
    static QMap<std::pair<QString,QString>,int>idFinder;
};


#endif // SCHEDULEOPTIMIZER_H
