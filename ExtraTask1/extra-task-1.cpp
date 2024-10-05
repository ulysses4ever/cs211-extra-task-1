#include "extra-task-1.h"

//Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

//Returns the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

//Returns the total number of hours in the specified number of hours, minutes, and seconds.
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(minutes < 60 && minutes >= 0);
    assert(seconds < 60 && seconds >= 0);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

//Returns the hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    return ((int)hours) % 24 + hours - (int)hours;
}

//Determines the hours part.
int get_hours(int s)
{
    return s / 3600;
}

//Determines the minutes part.
int get_minutes(int s)
{
    return (s % 3600) / 60;
}

//Determines the seconds part.
int get_seconds(int s)
{
    return (s % 3600) % 60;
}

//Returns time at UTC+0, where utc_offset is the number of hours away from UTC + 0.
double time_to_utc(int utc_offset, double time)
{
    if (time - utc_offset < 0)
    {
        return 24 + time - utc_offset;
    }
    else
    {
        if (time - utc_offset >= 24)
            return time - utc_offset - 24;
        return time - utc_offset;
    }
}

//Returns UTC time in time zone utc_offset.
double time_from_utc(int utc_offset, double time)
{
    if (time + utc_offset < 0)
    {
        return 24 + time + utc_offset;
    }
    else
    {
        if (time + utc_offset >= 24)
            return time + utc_offset - 24;
        return time + utc_offset;
    }
}
