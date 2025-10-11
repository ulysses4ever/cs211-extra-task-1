#include <cmath>

using namespace std;

double seconds_difference(double time_1, double time_2)
{
    /*
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
    return seconds_difference(time_1, time_2) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.

        Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
    */
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.

        Precondition: hours >= 0
    */
    return fmod(hours, 24.0);
}

int get_hours(int seconds)
{
    /*
        Determine the hours part of a time in seconds.
    */
    return seconds / 3600;
}

int get_minutes(int seconds)
{
    /*
        Determine the minutes part of a time in seconds.
    */
    return (seconds % 3600) / 60;
}

int get_seconds(int seconds)
{
    /*
        Determine the seconds part of a time in seconds.
    */
    return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from UTC+0.
    */
    double utc_time = time - utc_offset;

    // Корректировка для отрицательного времени и времени >= 24 часов
    if (utc_time < 0)
    {
        utc_time += 24.0;
    }
    else if (utc_time >= 24.0)
    {
        utc_time -= 24.0;
    }

    return utc_time;
}

double time_from_utc(int utc_offset, double time)
{
    /*
        Return UTC time in time zone utc_offset.
    */
    double local_time = time + utc_offset;

    // Корректировка для отрицательного времени и времени >= 24 часов
    if (local_time < 0)
    {
        local_time += 24.0;
    }
    else if (local_time >= 24.0)
    {
        local_time -= 24.0;
    }

    return local_time;
}