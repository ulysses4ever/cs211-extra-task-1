#include "extra-task-1.h"

#include "assert.h"
#include <iostream>
#include <cmath>


double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}


double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600;
}


double to_float_hours(int hours, int minutes, int seconds)
{
    assert(seconds >= 0 && seconds < 60);
    assert(minutes >= 0 && minutes < 60);
    
    return seconds / 3600.0 + minutes / 60.0 + hours;
}


double to_24_hour_clock(double hours)
{
    return fmod(hours, 24);
}


int get_hours(int seconds)
{
    return seconds / 3600;
}


int get_minutes(int seconds)
{
    return (seconds % 3600) / 60;
}


int get_seconds(int seconds)
{
    return seconds % 60;
}


double time_to_utc(int utc_offset, double time)
{
    return fmod((time - utc_offset) + 24, 24);
}


double time_from_utc(int utc_offset, double time)
{
    return fmod((time + utc_offset) + 24, 24);
}