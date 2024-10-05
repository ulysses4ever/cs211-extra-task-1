#include "extra-task-1.h"
double seconds_difference(double time_1, double time_2)
{
    // your implementation goes here...
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
    return (time_2 - time_1) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.

        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
    */
    assert(minutes >= 0 && minutes < 60);
    assert(seconds >= 0 && seconds < 60);
    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

double to_24_hour_clock(double hours)
{
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.

        Precondition: hours >= 0
        
    */
    assert(hours >= 0);
    double mts = hours - floor(hours);
    int hrs = floor(hours);
    return (hrs % 24) + mts;
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds. E.g.:
    In other words, if 3800 seconds have elapsed since midnight, 
    it is currently 01:03:20 (hh:mm:ss).
*/

int get_hours(int seconds)
{
    return (seconds / 3600) % 4;
}

int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

int get_seconds(int seconds)
{
    return seconds  % 60;
}

double time_to_utc(int utc_offset, double time)
{
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time
    */
    double t = time - utc_offset;
    if (t < 0)
    {
         t += 24;
    }
    else if (t >= 24)
    {
         t -= 24;
    }
    return t;
}

double time_from_utc(int utc_offset, double time)
{
    /*
        Return UTC time in time zone utc_offset.
    */
    return time_to_utc(-utc_offset, time);
}