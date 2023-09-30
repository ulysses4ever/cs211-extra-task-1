#include "extra-task-1.h"


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
    assert(minutes < 60 && minutes >= 0);
    assert(seconds < 60 && seconds >= 0);
    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    double x = hours;
    while (x >= 24)
        x -= 24;
    return x;
    
}


int get_hours(int seconds)
{
    int x = seconds / 3600;
    while (x >= 24)
        x -= 24;
    return x;
}

int get_minutes(int seconds)
{
    int x = seconds / 60;
    while (x >= 60)
        x -= 60;
    return x;
}

int get_seconds(int seconds)
{
    int x = seconds;
    while (x >= 3600)
    {
        x -= 3600;
    }
    while (x >= 60)
    {
        x -= 60;
    }
    return x;
}

double time_to_utc(int utc_offset, double time)
{
    double x = time - utc_offset;
    if (x >= 24)
        x -= 24;
    return x;
    
}

double time_from_utc(int utc_offset, double time)
{
    double x = time + utc_offset;
    if (x < 0)
        x += 24;
    if (x >= 24)
        x -= 24;
    return x;
}
