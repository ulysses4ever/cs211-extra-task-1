#include <cmath>
#include "assert.h"

//
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}
//Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600;
}
//Return the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
    assert((0 <= minutes && minutes < 60) && (0 <= seconds && seconds < 60));

    return (seconds / 3600.0) + (minutes / 60.0) + hours;
}
//
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    
    int wholeHours = int(hours);
    double fractHours = hours - wholeHours;
    return (wholeHours % 24) + fractHours;
}

/*
    There are implements three functions
        * get_hours
        * get_minutes
        * get_seconds
*/
int get_hours(int seconds)
{
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

int get_seconds(int seconds)
{
    return ((seconds % 3600) % 60) % 60;
}
//Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time)
{
    double resTime = 0;
    if ((time - utc_offset) > 0)
    {
        resTime = (time - utc_offset);
    }
    else
    {
        resTime = 24 + (time - utc_offset);
    }
    return to_24_hour_clock(resTime);
}
//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
    double resTime = 0;
    if ((time + utc_offset) > 0)
    {
        resTime = (time + utc_offset);
    }
    else
    {
        resTime = 24 + (time + utc_offset);
    }
    return to_24_hour_clock(resTime);
}
