#include "scheduleoptimizer.h"
#include "timeslotmodel.h"
ScheduleOptimizer::ScheduleOptimizer() {}

int ScheduleOptimizer:: getMinimumDays(int day, int time,int mask,bool take){
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
    if(reserved.find({day,time})!=reserved.end())
        return ans = fmin(ans,getMinimumDays(nxtday,nxttime,mask ,(nxtday==day))+(take==0));

   //////
   ///
    for (auto it: dayGrid[day] ) {
        if(mask & (1<<it)){
            continue;
        }
        ans = fmin(int(ans),int(recurse(nxtday,nxttime,(mask | (1<<it)),(nxtday==day))+(take==0)));
    }
    //hn leave
    ans = fmin(ans,getMinimumDays(nxtday,nxttime,mask ,nxttake));

    return ans;

}
