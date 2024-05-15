#include "scheduleoptimizer.h"
#include "UserConf.h"

#include <QVector>
std::map<std::pair<int,int>,int>ScheduleOptimizer:: requredAttendanceTimeSlots;
std::vector<std::vector<TimeSlot>>ScheduleOptimizer::minimizedTables;
std::vector<TimeSlot>ScheduleOptimizer::minimizedTable;
QMap<std::pair<QString,QString>,int> ScheduleOptimizer::idFinder;
std::vector<TimeSlot>ScheduleOptimizer::mandatoryTimeSlots;
int ScheduleOptimizer::initialMask;
int ScheduleOptimizer::  dp[7][7][1<<22][2];
ScheduleOptimizer::ScheduleOptimizer() {}

void getMandatorySlots(int section,QVector<QVector<QVector<TimeSlot>>>timeGrid,Lumen::UserConf userConf){
    QList<const Lumen::CourseAttendance*> attendedCourses =userConf.courseAttendances();
    std::vector<QString>mandatoryCourses;
    int x = 0;
    ScheduleOptimizer::initialMask = 0;
    for (auto it : attendedCourses) {
        if(it->hasLab()){
            ScheduleOptimizer::idFinder[{it->name(),"Lab"}] = x++;
            if(it->hasMandatoryLab()){
                mandatoryCourses.push_back(it->name());
                ScheduleOptimizer::initialMask= ScheduleOptimizer::initialMask |(x-1);
            }
        }
        if(it->hasLecture()){
            ScheduleOptimizer::idFinder[{it->name(),"Lecture"}] = x++;
            if(it->hasMandatoryLecture()){
                mandatoryCourses.push_back(it->name());
                ScheduleOptimizer::initialMask= ScheduleOptimizer::initialMask |(x-1);
            }
        }
        if(it->hasTutorial()){
            ScheduleOptimizer::idFinder[{it->name(),"Tutorial"}] = x++;
            if(it->hasMandatoryTutorial()){
                mandatoryCourses.push_back(it->name());
                ScheduleOptimizer::initialMask= ScheduleOptimizer::initialMask |(x-1);

            }
        }
    }
    for(auto it : mandatoryCourses){
        for(auto schedule : timeGrid){
            for(auto day : schedule){
                for(auto timeSlot : day){
                    if(it == timeSlot.course && timeSlot.sectionNumbers == section){
                        ScheduleOptimizer:: mandatoryTimeSlots.push_back(timeSlot);
                        ScheduleOptimizer:: requredAttendanceTimeSlots[{timeSlot.day,timeSlot.timePeriod}] = ScheduleOptimizer::mandatoryTimeSlots.size();
                    }
                }
            }
        }
    }
}


int ScheduleOptimizer:: getMinimumDays(int day, int time,int mask,bool take,std::vector<std::vector<std::vector<TimeSlot>>>dayGrid){
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
            if(mask & (1<<idFinder[{it.course,it.type}])||idFinder.find({it.course,it.type})==idFinder.end()){
                continue;
            }
            ans = fmin(int(ans),int(getMinimumDays(nxtday,nxttime,(mask | (1<<idFinder[{it.course,it.type}])),(nxtday==day),dayGrid)+(take==0)));
        }
    }

    //hn leave
    ans = fmin(ans,getMinimumDays(nxtday,nxttime,mask ,nxttake,dayGrid));

    return ans;

}

void ScheduleOptimizer:: buildOptimizedSchedules(int day, int time,int mask,bool take,std::vector<std::vector<std::vector<TimeSlot>>>dayGrid){

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
        minimizedTable.push_back(mandatoryTimeSlots[requredAttendanceTimeSlots[{day,time}]]);
        buildOptimizedSchedules(nxtDay, nxtTime, mask, (nxtDay==day),dayGrid);
        minimizedTable.pop_back();
        return;
    }
    for(int schedule = 0; schedule < dayGrid.size();schedule++){
        for (int i = time; i < dayGrid[schedule][day].size();i+=6) {
            auto it =dayGrid[schedule][day][i];
            if(mask & (1<<idFinder[{it.course,it.type}])||idFinder.find({it.course,it.type})==idFinder.end()){
                continue;
            }
            if((getMinimumDays(nxtDay,nxtTime,(mask | (1<<idFinder[{it.course,it.type}])),(nxtDay==day),dayGrid)+(take==0))==ans)
            {
                minimizedTable.push_back(it);
                buildOptimizedSchedules(nxtDay,nxtTime,(mask | (1<<idFinder[{it.course,it.type}])),(nxtDay==day),dayGrid);
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
