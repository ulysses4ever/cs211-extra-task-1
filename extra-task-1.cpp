#include "extra-task-1.h"

//Return the number of seconds later that a time in seconds
//time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

//Return the number of hours later that a time in seconds
//time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
    return seconds_difference(time_1, time_2) / 3600;
}

//Return the total number of hours in the specified number
//of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
    assert((0 <= minutes) && (minutes < 60));
    assert((0 <= seconds) && (seconds < 60));
    assert(0 <= hours);

    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

// hours is a number of hours since midnight. Return the
//hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
    return int(hours) % 24 + (hours - int(hours));
}
//used to determine the hours part of a time in seconds.
int get_hours(int seconds)
{
    assert(seconds >= 0);
    return seconds / 3600;
}
//used to determine the minutes part of a time in seconds.
int get_minutes(int seconds)
{
    assert(seconds >= 0);
    return (seconds - get_hours(seconds) * 3600) / 60;
}
//used to determine the seconds part of a time in seconds.
int get_seconds(int seconds)
{
    assert(seconds >= 0);
    return (seconds - get_hours(seconds) * 3600) - get_minutes(seconds) * 60;
}

//Return time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time)
{
    double t = (-1 * utc_offset) + time;
    return t - (int(t) / 24 * 24);
}

//Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
    double t = time + utc_offset;
    if (t < 0)
    {
        return 24 + t;
    }
    if (t >= 24)
        return t - (int(t) / 24 * 24);
    return t;
}
