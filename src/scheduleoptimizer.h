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
#include <unordered_map>
#include<QPair>
#include <QList>
#include<QMap>
#include <QtGlobal>
#include "timeslot.h"
class ScheduleOptimizer
{
public:
    ScheduleOptimizer();
    static int getMinimumDays(int day, int time,int  mask,bool take,QVector<QVector<QVector<TimeSlot>>>timeGrid);
    static int getMandatorySlots(int section,QVector<QVector<QVector<TimeSlot>>>timeGrid);
    static void buildOptimizedSchedules(int day, int time,int mask,bool take,QVector<QVector<QVector<TimeSlot>>>timeGrid);
    const static int MASK = (1<<6)-1;
    int initialMask = 0;
    static QMap<std::pair<int,int>,std::pair<int,TimeSlot>> requredAttendanceTimeSlots;
    static QVector<QVector<TimeSlot>>minimizedTables;
    static QVector<TimeSlot>minimizedTable;
    static int dp[7][7][1<<22][2];
    static std::unordered_map<QString,int>idFinder;
};


#endif // SCHEDULEOPTIMIZER_H
