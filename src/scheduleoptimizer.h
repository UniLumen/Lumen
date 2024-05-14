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
    static int getMinimumDays(int day, int time,int mask,bool take);
    static int buildOptimizedSchedules(int day, int time,int mask,bool take);
    const static int MASK = (1<<6)-1;
    int initialMask = 0;
    static QMap<QPair<int,int>,int> reserved;
    static QVector<QVector<QVector<int>>>ans;
    static QVector<QVector<int>>path;
    static int dp[6][6][1<<24][2];
    static std::unordered_map<QString,int>idFinder;
};


#endif // SCHEDULEOPTIMIZER_H
