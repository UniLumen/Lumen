#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include "timeslot.h"
#include <QDebug>

#include <QObject>
#include <QAbstractListModel>
#include <QString>
#include <vector>
#include <unordered_map>

#include <QList>
#include <QtGlobal>

std::unordered_map<int, QVector<int>> schedule[6];
QVector<QVector<QVector<int>>>ans;
QVector<QVector<int>>path;
const int DAYS =6,TIMES = 13,MASK = (1<<6)-1;
int dp[DAYS][TIMES][1<<8][2];
const QVector<int> timeSlots = {8, 10, 12, 2, 4, 6};
std::unordered_map<QPair<int,int>,int> r;

