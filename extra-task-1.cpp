#include <cmath>
#include "extra-task-1.h"
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    return (time_2-time_1)/3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    return hours + (minutes / 60) + (seconds / 3600);
}

double to_24_hour_clock(double hours)
{
    return (((int)trunc(hours) % 24) + (hours - trunc(hours)));
}

double get_hours(double sec)
{
    return trunc(sec / 3600.0);
}
double get_minutes(double sec)
{
    return trunc((sec - get_hours(sec) * 3600) / 60.0);
}
double get_seconds(double sec)
{
    return (sec - get_minutes(sec) * 60 - get_hours(sec) * 3600);
}

double time_to_utc(int utc_offset, double time)
{
    return to_24_hour_clock(time - utc_offset);
}

double time_from_utc(int utc_offset, double time)
{
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
