#include "extra-task-1.h"
#include <assert.h>
#include <cmath>

// Return the number of seconds later that a time in seconds
// time_2 is than a time in seconds time_1
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

// Return the number of hours later that a time in seconds
// time_2 is than a time in seconds time_1
double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600.0;
}

// Return the total number of hours in the specified number
// of hours, minutes, and seconds
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);

    return hours + minutes / 60.0 + seconds / 3600.0;
}

// hours is a number of hours since midnight. Return the
// hour as seen on a 24 - hour clock
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);

    return fmod(hours, 24.0);
}

// Determine the hours part of a time in seconds
int get_hours(int seconds)
{
    return seconds / 3600;
}
// Determine the minutes part of a time in seconds
int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}
// Determine the seconds part of a time in seconds
int get_seconds(int seconds)
{
    return seconds % 60;
}

// Return time at UTC + 0, where utc_offset is the number of hours away from
// UTC + 0
double time_to_utc(int utc_offset, double time)
{
    double res = time - utc_offset;

    if (res < 0)
        res += 24;
    else if (res >= 24)
        res -= 24;

    return res;
}

// Return UTC time in time zone utc_offset
double time_from_utc(int utc_offset, double time)
{
    double result = time + utc_offset;
    
    if (result < 0)
        result += 24;
    else if (result >= 24)
        result -= 24;

    return result;
}