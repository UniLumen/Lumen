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
class ScheduleOptimizer
{
public:
    ScheduleOptimizer();
};


QMap<QPair<int,int>,int> reserved;
std::unordered_map<int, QVector<int>> schedule[6];
QVector<QVector<QVector<int>>>ans;
QVector<QVector<int>>path;
const int DAYS =6,TIMES = 13,MASK = (1<<6)-1;
int dp[DAYS][TIMES][1<<8][2];
const QVector<int> timeSlots = {8, 10, 12, 2, 4, 6};

#endif // SCHEDULEOPTIMIZER_H
