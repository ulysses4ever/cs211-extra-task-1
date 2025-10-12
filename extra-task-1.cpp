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
// Convenes the time
double time_to_utc(int utc_offset, double time)
{
    double utc_time = time - utc_offset;
    if (utc_time >= 24.0)
        utc_time -= 24.0;
    else if (utc_time < 0.0)
        utc_time += 24.0;
    return utc_time;
}
// Ñonverts time from UTC+0
double time_from_utc(int utc_offset, double time)
{
    double local_time = time + utc_offset;
    if (local_time >= 24.0)
        local_time -= 24.0;
    else if (local_time < 0.0)
        local_time += 24.0;
    return local_time;
}
// Approximate double comparison
bool are_equal(double a, double b)
{
    return fabs(a - b) < DBL_EPSILON;
}
