#include "XTask1/extra-task-1.h"

// Return the number of seconds later that a time in seconds
// time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

// Return the number of hours later that a time in seconds
// time_2 is than a time in seconds time_1.1
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}


// Return the total number of hours in the specified number
// of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);
    return hours+(minutes + seconds / 60.0) / 60.0;
}

// Hours is a number of hours since midnight. Return the
// hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    double int_part;                                   
    double frac_part = modf(hours, &int_part);         
    return static_cast<double>(static_cast<int>(int_part) % 24) + frac_part;
}


// Return the hours that have elapsed since midnight;
double get_hours(int seconds)
{
    return (seconds / 3600) % 24;
}

// Return the minutes that have elapsed since midnight;
double get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}

// Return the seconds that have elapsed since midnight;
double get_seconds(int seconds)
{
    return seconds % 60;
}

// Return time at UTC+0, where utc_offset is the number of hours away from
// UTC + 0.
double time_to_utc(int utc_offset, double time)
{
    double result = time - static_cast<double>(utc_offset);
    result = fmod(result, 24.0);
    if (result < 0.0)
        result += 24.0;
    return result;

}

// Return UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
    double result = time + static_cast<double>(utc_offset);
    result = fmod(result, 24.0);
    if (result < 0.0)
        result += 24.0;
    return result;
}
