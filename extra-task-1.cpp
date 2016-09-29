#include <bits/stdc++.h>
using namespace std;


/* Return the number of seconds later that a time in seconds
time_2 is than a time in seconds time_1. */
double seconds_difference(double time_1, double time_2)
{
    assert(time_1 >= 0 && "seconds_difference: time_1 >= 0");
    assert(time_2 >= 0 && "seconds_difference: time_2 >= 0");

    return time_2 - time_1;
}


/* Return the number of hours later that a time in seconds
time_2 is than a time in seconds time_1. */
double hours_difference(double time_1, double time_2)
{
    assert(time_1 >= 0 && "hours_difference: time_1 >= 0");
    assert(time_2 >= 0 && "hours_difference: time_2 >= 0");

    return seconds_difference(time_1, time_2) / 3600;
}


/* Return the total number of hours in the specified number
of hours, minutes, and seconds. */
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(hours >= 0 && "to_float_hours: hours >= 0");
    assert(0 <= minutes && minutes < 60 && "to_float_hours: 0 <= minutes < 60");
    assert(0 <= seconds && seconds < 60 && "to_float_hours: 0 <= seconds < 60");

    return (double)hours + (double)minutes / 60 + (double)seconds / 3600;
}


/* hours is a number of hours since midnight. Return the
hour as seen on a 24-hour clock. */
double to_24_hour_clock(double hours)
{
    assert(hours >= 0 && "to_24_hour_clock: hours >= 0");

    return hours - int(hours / 24) * 24;
}


/* Return number of hours in 'time' */
int get_hours(int time)
{
    assert(time >= 0 && "get_hours: time >= 0");

    return time / 3600;
}


/* Return number of minutes in 'time' */
int get_minutes(int time)
{
    assert(time >= 0 && "get_minutes: time >= 0");

    return (time % 3600) / 60;
}


/* Return number of seconds in 'time' */
int get_seconds(int time)
{
    assert(time >= 0 && "get_seconds: time >= 0");

    return time % 60;
}


/* Return time at UTC+0, where utc_offset is the number of hours away from UTC+0. */
double time_to_utc(int utc_offset, double time)
{
    assert(time >= 0 && "time_to_utc: time >= 0");
    assert(-12 <= utc_offset && utc_offset <= 14 && "time_to_utc: -12 <= utc_offset <= 14");

    double result = time - utc_offset;

    if (result < 0)
        return result + 24.;

    if (result + DBL_EPSILON >= 24)
        return result - 24.;

    return result;
}


/* Return UTC time in time zone utc_offset. */
double time_from_utc(int utc_offset, double time)
{
    assert(time >= 0 && "time_from_utc: time >= 0");
    assert(-12 <= utc_offset && utc_offset <= 14 && "time_from_utc: -12 <= utc_offset <= 14");

    double result = time + utc_offset;

    if (result < 0)
        return result + 24.;

    if (result + DBL_EPSILON >= 24)
        return result - 24.;

    return result;
}
