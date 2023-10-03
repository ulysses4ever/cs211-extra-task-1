#include "extra-task-1.h"
#include <cmath>
#include <cassert>

/// <summary>
/// checks if two double numbers are equal with 10^-7 accuracy
/// </summary>
/// <param name="d1"></param>
/// <param name="d2"></param>
/// <returns></returns>
bool equal(double d1, double d2)
{
    double eps = 1e-7;
    return fabs(d1 - d2) < eps;
}

/// <summary>
/// Returns the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
/// </summary>
/// <param name="time_1">Time1 in seconds</param>
/// <param name="time_2">Time2 in seconds</param>
/// <returns></returns>
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

/// <summary>
/// Return the number of hours later that a time in seconds
/// time_2 is than a time in seconds time_1.
/// </summary>
/// <param name="time_1">time_1 in seconds</param>
/// <param name="time_2">time_2 in seconds</param>
/// <returns></returns>
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600;
}

/// <summary>
/// Returns the total number of hours in the specified number
/// of hours, minutes, and seconds.
/// </summary>
/// <param name="hours">Hours</param>
/// <param name="minutes">Minutes</param>
/// <param name="seconds">Seconds</param>
/// <returns></returns>
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes <= 60);
    assert(0 <= seconds && seconds <= 60);
    
    return hours + (minutes / 60.0) + (seconds / 3600.0);
}

/// <summary>
/// Returns the hour as seen on the clock by given number of hours since midnight
/// </summary>
/// <param name="hours">Number of hours since midnight</param>
/// <returns></returns>
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);

    double hour;
    double mins = modf(hours, &hour);
    
    return (int)hour % 24 + mins;
}

/// <summary>
/// Returns the hours part in given time in seconds
/// </summary>
/// <param name="time">Time in seconds</param>
/// <returns></returns>
int get_hours(int time)
{
    return time / 3600;
}

/// <summary>
/// Returns the minutes part in given time in seconds
/// </summary>
/// <param name="time">Time in seconds</param>
/// <returns></returns>
int get_minutes(int time)
{
    return time / 60 % 60;
}

/// <summary>
/// Returns the seconds part in given time in seconds
/// </summary>
/// <param name="time">Time in seconds</param>
/// <returns></returns>
int get_seconds(int time)
{
    return time % 3600 % 60;
}

/// <summary>
/// Converts given time to UTC+0 depends on the offset
/// </summary>
/// <param name="utc_offset">The offset</param>
/// <param name="time">Time</param>
/// <returns></returns>
double time_to_utc(int utc_offset, double time)
{
    double hour;
    double min_sec = modf(time, &hour);

    return ((int)hour - utc_offset) % 24 + min_sec;
}

/// <summary>
/// COnverts time from UTC+0 to given offset
/// </summary>
/// <param name="utc_offset">Offset</param>
/// <param name="time">Time in UTC+0</param>
/// <returns></returns>
double time_from_utc(int utc_offset, double time)
{
    double hour;
    double min_sec = modf(time, &hour);

    int res = ((int)hour + utc_offset) % 24;
    
    if (res < 0) res = 24 - abs(res);
    
    return res + min_sec;
}
