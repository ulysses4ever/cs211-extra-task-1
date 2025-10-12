#include <iostream>
#include "extra-task-1.h"
// Calculates the difference in seconds between two timestamps
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}
// Calculates the time difference in hours between two timestamps
double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600.0;
}
// Returns the total amount of time in hours
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes < 60 && 0 <= seconds && seconds < 60);
    return hours + (minutes / 60.0) + (seconds / 3600.0);
}
// Translates "time from midnight" to "time on the clock"
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    return fmod(hours, 24);
}
// Returns the whole number of hours
int get_hours(int seconds)
{
    assert(seconds >= 0);
    return seconds / 3600 % 24;
}
// Returns an integer number of minutes
int get_minutes(int seconds)
{
    assert(seconds >= 0);
    return seconds % 3600 / 60;
}
// Returns an integer number of seconds
int get_seconds(int seconds)
{
    assert(seconds >= 0);
    return seconds % 60;
}
//
double time_to_utc(int utc_offset, double time)
{
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
    return 0;
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
    return 0;
}
// Приближенное сравнения double
bool are_equal(double a, double b)
{
    return fabs(a - b) < DBL_EPSILON;
}
