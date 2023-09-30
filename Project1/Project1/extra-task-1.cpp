#include "extra-task-1.h"


double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
    
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes < 60 && minutes >= 0);
    assert(seconds < 60 && seconds >= 0);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    double x = hours;
    while (x >= 24)
        x -= 24;
    return x;
    
}


int get_hours(int seconds)
{
    int x = seconds / 3600;
    while (x >= 24)
        x -= 24;
    return x;
}

int get_minutes(int seconds)
{
    int x = seconds / 60;
    while (x >= 60)
        x -= 60;
    return x;
}

int get_seconds(int seconds)
{
    int x = seconds;
    while (x >= 3600)
    {
        x -= 3600;
    }
    while (x >= 60)
    {
        x -= 60;
    }
    return x;
}

double time_to_utc(int utc_offset, double time)
{
    return 0;
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time

        >>> time_to_utc(+0, 12.0)
        12.0
 
        >>> time_to_utc(+1, 12.0)
        11.0
 
        >>> time_to_utc(-1, 12.0)
        13.0
 
        >>> time_to_utc(-11, 18.0)
        5.0
 
        >>> time_to_utc(-1, 0.0)
        1.0
 
        >>> time_to_utc(-1, 23.0)
        0.0
    */
}

double time_from_utc(int utc_offset, double time)
{
    return 0;
    /*
        Return UTC time in time zone utc_offset.

        >>> time_from_utc(+0, 12.0)
        12.0
 
        >>> time_from_utc(+1, 12.0)
        13.0
 
        >>> time_from_utc(-1, 12.0)
        11.0
 
        >>> time_from_utc(+6, 6.0)
        12.0
 
        >>> time_from_utc(-7, 6.0)
        23.0
 
        >>> time_from_utc(-1, 0.0)
        23.0
 
        >>> time_from_utc(-1, 23.0)
        22.0
 
        >>> time_from_utc(+1, 23.0)
        0.0
    */
}
