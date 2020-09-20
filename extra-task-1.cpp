#include "extra-task-1.h"
#include "assert.h"
#include <cmath>
double seconds_difference(double time_1, double time_2)
{
    
    return time_2-time_1;
}

double hours_difference(double time_1, double time_2)
{ 
    return  (time_2 - time_1) / 3600;
}
   

double to_float_hours(int hours, int minutes, int seconds)
{  
    assert(0 <= minutes && minutes < 60 && 0 <= seconds && seconds < 60);
    return hours + minutes/60.0 + seconds/3600.0;
   
}

double to_24_hour_clock(double hours)
{  
    assert(hours>=0);
    return fmod(hours,24);
    
       /*
        You may wish to inspect various function in <cmath> to work
        with integer and fractional part of a hours separately.
        
    */
}

int get_hours(int seconds)
{
    assert(seconds>=0);
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    assert(seconds >= 0);
    return (seconds % 3600)/60;
}

int get_seconds(int seconds)
{
    assert(seconds>=0);
    return (seconds % 3600 ) % 60;
}
/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds. E.g.:

*/

double time_to_utc(int utc_offset, double time)
{  
    assert(utc_offset>=-12 && utc_offset<=14);
    assert(time >= 0 && time < 24);
    return fmod(time-utc_offset,24);
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time
       
    */
}

double time_from_utc(int utc_offset, double time)
{ 
    assert(utc_offset >= -12 && utc_offset <= 14);
    assert(time >= 0 && time < 24);
    return fmod(utc_offset+time+24,24);
    /*
        Return UTC time in time zone utc_offset.
 
        >>> time_from_utc(+1, 23.0)
        0.0
    */
}
