#include "scheduleoptimizer.h"
#include <QVector>
QMap<std::pair<int,int>,std::pair<int,TimeSlot>>ScheduleOptimizer:: requredAttendanceTimeSlots;
QVector<QVector<TimeSlot>>ScheduleOptimizer::minimizedTables;
QVector<TimeSlot>ScheduleOptimizer::minimizedTable;
std::unordered_map<QString,int>ScheduleOptimizer::idFinder;
int ScheduleOptimizer::  dp[7][7][1<<22][2];
ScheduleOptimizer::ScheduleOptimizer() {}

void getMandatorySlots(int section,QVector<QVector<QVector<TimeSlot>>>timeGrid){

}


int ScheduleOptimizer:: getMinimumDays(int day, int time,int mask,bool take,QVector<QVector<QVector<TimeSlot>>>dayGrid){
    if(day ==6){
        return (MASK!=mask) * 18;
    }
    int nxtday , nxttime;
    bool nxttake;
    if(time == 6) {
        nxtday = day + 1;
        nxttime = 8;
        nxttake = 0;
    }
    else{
        nxtday = day;
        nxttime = ((time + 1)%12)+1;
        nxttake = take;
    }
    int &ans = dp[day][time][mask][take];
    if(~ans){
        return ans;
    }
    else
    {
        ans = INT32_MAX;
    }
    if(time%7==0){
        return ans = fmin(ans,getMinimumDays(nxtday,nxttime,mask ,nxttake,dayGrid));
    }
    if(requredAttendanceTimeSlots.find({day,time})!=requredAttendanceTimeSlots.end())
        return ans = fmin(ans,getMinimumDays(nxtday,nxttime,mask ,(nxtday==day),dayGrid)+(take==0));
    for(int schedule = 0; schedule < dayGrid.size();schedule++){
        for (int i = time; i < dayGrid[schedule][day].size() ; i+=6) {
            auto it = dayGrid[schedule][day][i];
            if(mask & (1<<idFinder[it.course])||idFinder.find(it.course)==idFinder.end()){
                continue;
            }
            ans = fmin(int(ans),int(getMinimumDays(nxtday,nxttime,(mask | (1<<idFinder[it.course])),(nxtday==day),dayGrid)+(take==0)));
        }
    }

    //hn leave
    ans = fmin(ans,getMinimumDays(nxtday,nxttime,mask ,nxttake,dayGrid));

    return ans;

}

void ScheduleOptimizer:: buildOptimizedSchedules(int day, int time,int mask,bool take,QVector<QVector<QVector<TimeSlot>>>dayGrid){

    if(day ==6){
        if(MASK==mask){
            minimizedTables.push_back(minimizedTable);
        }
        return ;
    }
    int nxtDay , nxtTime;
    bool nxtTake;
    if(time == 6) {
        nxtDay = day + 1;
        nxtTime = 8;
        nxtTake = 0;
    }
    else{
        nxtDay = day;
        nxtTime = ((time + 1)%12)+1;
        nxtTake = take;
    }

    int &ans = dp[day][time][mask][take];
    //take
    if(time%7==0){
        buildOptimizedSchedules(nxtDay,nxtTime,mask ,nxtTake,dayGrid);
    }
    if(requredAttendanceTimeSlots.find({day,time})!=requredAttendanceTimeSlots.end()) {
        buildOptimizedSchedules(nxtDay, nxtTime, mask, (nxtDay==day),dayGrid);
        minimizedTable.pop_back();
        return;
    }
    for(int schedule = 0; schedule < dayGrid.size();schedule++){
        for (int i = time; i < dayGrid[schedule][day].size();i+=6) {
            auto it =dayGrid[schedule][day][i];
            if(mask & (1<<idFinder[it.course])||idFinder.find(it.course)==idFinder.end()){
                continue;
            }
            if((getMinimumDays(nxtDay,nxtTime,(mask | (1<<idFinder[it.course])),(nxtDay==day),dayGrid)+(take==0))==ans)
            {
                minimizedTable.push_back(it);
                buildOptimizedSchedules(nxtDay,nxtTime,(mask | (1<<idFinder[it.course])),(nxtDay==day),dayGrid);
                minimizedTable.pop_back();
            }
        }
    }
    //hn leave
    if(getMinimumDays(nxtDay,nxtTime,mask ,nxtTake,dayGrid)==ans)
    {
        buildOptimizedSchedules(nxtDay,nxtTime,mask ,nxtTake,dayGrid);
    }
}
