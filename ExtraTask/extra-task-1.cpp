#include <cmath>
#include <cassert>

//Returns the number of seconds later that a time in seconds time_2 is than a time in seconds time_1
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

//Returns the number of hours later that a time in seconds time_2 is than a time in seconds time_1
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

//Returns the total number of hours in the specified number of hours, minutes, and seconds
double to_float_hours(int hours, int minutes, int seconds)
{
    assert((0 <= minutes < 60) && (0 <= seconds < 60));
    int secondsTotal = hours * 3600 + minutes * 60 + seconds;
    return secondsTotal / 3600.0;
}

//Return the number of hours since midnight as seen on a 24 - hour clock
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    double intPart = 0;
    double fractionalPart = modf(hours, &intPart);
    return ((int)intPart % 24) + fractionalPart;
}

//Hours part of a time in seconds
int get_hours(int seconds)
{
    return seconds / 3600;
}

//Minutes part of a time in seconds
int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

//Seconds part of a time in seconds
int get_seconds(int seconds)
{
    return seconds % 3600 % 60;
}

//Returns time at UTC+0, where utc_offset is the number of hours away from UTC + 0
double time_to_utc(int utc_offset, double time)
{
    return to_24_hour_clock(time - utc_offset);
}

//Returns UTC time in time zone utc_offset
double time_from_utc(int utc_offset, double time)
{
    double utc_time = time + utc_offset;
    if (utc_time >= 0) return to_24_hour_clock(utc_time);
    return to_24_hour_clock(24.0 - abs(utc_time));
}
