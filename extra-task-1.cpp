#include "extra-task-1.h"
#include <cassert>;
#include <cmath>

// Return the number of seconds later that a time in seconds
// time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{   
    return time_2 - time_1;

}

//Return the number of hours later that a time in seconds
//time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
   
}
/*
    Return the total number of hours in the specified number
    of hours, minutes, and seconds.
*/
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes >= 0 && minutes < 60);
    assert(seconds >= 0 && seconds < 60);

    return hours + (minutes / 60.0) + (seconds / 3600.0);

}

// hours is a number of hours since midnight. Return the 
// hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    return fmod(hours, 24);
}
//functions: get_hours, get_minutes, get_seconds.
//They are used to determine the hours part, minutes part and seconds part 
//of a time in seconds.E.g.:
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
    return seconds % 60;
}
// Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time)
{
    return fmod((time - utc_offset)+24.0, 24);
}

//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
    return fmod((time + utc_offset) + 24.0, 24);

}
